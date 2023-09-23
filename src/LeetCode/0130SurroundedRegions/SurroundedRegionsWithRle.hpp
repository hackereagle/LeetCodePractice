#pragma once

#include "ISurroundedRegions.hpp"

class SurroundedRegionsWithRle : public ISurroundedRegions
{
public:
	~SurroundedRegionsWithRle() override {}

	void solve(std::vector<std::vector<char>> &board) override
	{
		std::vector<std::vector<SubRowReg*>> allRegs(board.size(), std::vector<SubRowReg*>());
		std::vector<Region*> regions;
		//PrintBoard(board);

		GatherAllSubRegion(board, allRegs);	 

		ConnectSubRegionsToRegion(allRegs, regions);

		ChangeBoardSourndRengionX2O(board, regions);
		//std::cout << "\nresult:" << std::endl;
		//PrintBoard(board);

		ReleaseAllRegions(regions);
		allRegs.clear();
	}

private:
	typedef struct subRowReg
	{
		int Row = -1;
		int Start = -1;
		int End = -1;
		int RegionNo = -1;

		subRowReg(int r, int s, int e, int no) : Row(r), Start(s), End(e), RegionNo(no) {}
	}SubRowReg;

	typedef struct point
	{
		int Row = -1;
		int Col = -1;

		point() = default;
		point(int r, int c) : Row(r), Col(c) {}

		friend std::ostream& operator<<(std::ostream& os, const point& p)
		{
			os << "[" << p.Row << ", " << p.Col << "]";
			return os;
		}
	}Point;

	typedef struct region
	{
	public:
		int RegionNo = -1;
		Point TopLeft;
		Point BottomRight;
		std::vector<SubRowReg*> SubRegions;

		region() = default;
		region(int no, Point tl, Point br) : RegionNo(no), TopLeft(tl), BottomRight(br) {}
		region(int no, SubRowReg* subReg)
		{
			RegionNo = no;
			TopLeft = Point(subReg->Row, subReg->Start);
			BottomRight = Point(subReg->Row, subReg->End);
			subReg->RegionNo = no;
			SubRegions.push_back(subReg);
		}

		void AddSubRegion(SubRowReg* subReg, std::vector<region*> &regions)
		{
			if (subReg->RegionNo == -1) {
				AddOneSubRegion(subReg);
			}
			else {
				Region* target = nullptr;
				int index = -1;
				for (int i = 0; i < regions.size(); i++) {
					if (regions[i]->RegionNo == subReg->RegionNo && regions[i]->RegionNo != this->RegionNo) {
						target = regions[i];
						index = i;
						break;
					}
				}

				if (index == -1)
					return;

				for (int i = 0; i < target->SubRegions.size(); i++) {
					AddOneSubRegion(target->SubRegions[i]);
				}
				
				regions.erase(regions.begin() + index);
			}
		}

	private:
		void AddOneSubRegion(SubRowReg* subReg)
		{
			if (subReg->Row > this->BottomRight.Row) {
				this->BottomRight.Row = subReg->Row;
			}
			else if (subReg->Row < this->TopLeft.Row) {
				this->TopLeft.Row = subReg->Row;
			}

			if (subReg->End > this->BottomRight.Col) {
				this->BottomRight.Col = subReg->End;
			}

			if (subReg->Start < this->TopLeft.Col) {
				this->TopLeft.Col = subReg->Start;
			}

			subReg->RegionNo = this->RegionNo;
			this->SubRegions.push_back(subReg);
		}
	}Region;

	void ReleaseRegion(Region* &reg)
	{
		if (reg) {
			for (int i = 0; i < reg->SubRegions.size(); i++) {
				delete reg->SubRegions[i];
				reg->SubRegions[i] = nullptr;
			}
			delete reg;
			reg = nullptr;
		}
	}

	void ReleaseAllRegions(std::vector<Region*> regions)
	{
		for (int i = 0; i < regions.size(); i++)
			ReleaseRegion(regions[i]);
	}

	void CollectRegion(std::vector<std::vector<SubRowReg*>> &allRegs, int r, int c, SubRowReg* &curRegion)
	{
		if (curRegion == nullptr) {
			curRegion = new SubRowReg(r, c, c, -1);
			allRegs[r].push_back(curRegion);
		}
		else {
			curRegion->End = c;
		}
	}

	void GatherAllSubRegion(std::vector<std::vector<char>> &board, std::vector<std::vector<SubRowReg*>> &allRegs)
	{
		int rows = board.size();
		int cols = board[0].size();
		SubRowReg* curRegion = nullptr;
		// gather all subregion
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if ('O' == board[i][j])
					CollectRegion(allRegs, i, j, curRegion);
				else {
					curRegion = nullptr;
				}
			}
			curRegion = nullptr;
		}
	}

	std::vector<SubRowReg*> FindNearbyRegion(SubRowReg* cur, std::vector<SubRowReg*> &aRowSubRegs)
	{
		std::vector<SubRowReg*> ret;

		for (int i = 0; i < aRowSubRegs.size(); i++) {
			if ((cur->Start <= aRowSubRegs[i]->Start && cur->End >= aRowSubRegs[i]->End)   ||
				(cur->Start >= aRowSubRegs[i]->Start && cur->Start <= aRowSubRegs[i]->End) ||
				(cur->End >= aRowSubRegs[i]->Start && cur->End <= aRowSubRegs[i]->End)) {
				ret.push_back(aRowSubRegs[i]);
			}
		}
		return ret;
	}

	void UnionNearbySubRegion(std::vector<SubRowReg*> &candidate, SubRowReg* curSubReg, std::vector<Region*> &regions)
	{
		//std::cout << "In UnionNearbySubRegion, amount of candidate = " << candidate.size() << std::endl; // debug
		Region* tmp = nullptr;
		for (int i = 0; i < candidate.size(); i++) {
			//std::cout << "\tCandidate " << i << "-th, no = " << candidate[i]->RegionNo << ", row = " << candidate[i]->Row << ", " << candidate[i]->Start << ", " << candidate[i]->End << std::endl;
			for (int j = 0; j < regions.size(); j++) {
				if (candidate[i]->RegionNo == regions[j]->RegionNo) {
					//std::cout << "\t\t" << j << "-th region, no = " << regions[j]->RegionNo << ", " << regions[j]->TopLeft << ", " << regions[j]->BottomRight << " will be add" << std::endl; // debug
					tmp = regions[j];
					break;
				}
			}
			//std::cout << "\t\tcurSubReg->RegionNo = " << curSubReg->RegionNo << std::endl;
			tmp->AddSubRegion(curSubReg, regions);
		}
	}

	void ConnectSubRegionsToRegion(std::vector<std::vector<SubRowReg*>> &allSubRegs, std::vector<Region*> &regions)
	{
		int beginRow = 0;
		for (int i = 0; i < allSubRegs.size(); i++) {
			if (allSubRegs[i].size() > 0) {
				beginRow = i;
				break;
			}
		}

		int regCount = 0;
		for (int i = 0; i < allSubRegs[beginRow].size(); i++) {
			Region* cur = new Region(regCount + 1, allSubRegs[beginRow][i]);
			regions.push_back(cur);
			regCount = regCount + 1;
		}

		std::vector<SubRowReg*> candidates;
		for (int i = beginRow + 1; i < allSubRegs.size(); i++) {
			for (SubRowReg* reg : allSubRegs[i]) {
				candidates = FindNearbyRegion(reg, allSubRegs[i - 1]);

				if (candidates.size() > 0) {
					UnionNearbySubRegion(candidates, reg, regions);
				}
				else {
					Region* cur = new Region(regCount + 1, reg);
					regions.push_back(cur);
					regCount = regCount + 1;
				}
			}
		}

		for (int i = 0; i < regions.size(); i++) {
			regions[i]->RegionNo = i + 1;
		}
	}

	void ChangeX2O(std::vector<std::vector<char>> &board, Region* &region)
	{
		int start = 0, end = 0, row = 0;
		for (int i = 0; i < region->SubRegions.size(); i++) {
			start = region->SubRegions[i]->Start;
			end = region->SubRegions[i]->End;
			row = region->SubRegions[i]->Row;
			for (int j = start; j <= end; j++) {
				board[row][j] = 'X';
			}
		}
	}

	void ChangeBoardSourndRengionX2O(std::vector<std::vector<char>> &board, std::vector<Region*> &regions)
	{
		int rows = board.size();
		int cols = board[0].size();
		for (int i = 0; i < regions.size(); i++) {
			//std::cout << "region index = " << i << ", no = " << regions[i]->RegionNo << ", top left = " << regions[i]->TopLeft << ", bottom right = " << regions[i]->BottomRight << std::endl; // debug
			if (regions[i]->TopLeft.Row != 0 && regions[i]->TopLeft.Col != 0 &&
				regions[i]->BottomRight.Row != rows - 1 && regions[i]->BottomRight.Col != cols - 1) {
				//std::cout << "\tThis region become X" << std::endl; // debug
				ChangeX2O(board, regions[i]);
			}
		}
	}

	void PrintBoard(std::vector<std::vector<char>> &board)
	{
		for (auto r : board) {
			for (auto c : r) {
				std::cout << (char)c << " ";
			}
			std::cout << std::endl;
		}
	}
};