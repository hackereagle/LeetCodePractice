#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include "AssertClass.hpp"
#include "VectorMiscs.hpp"

class Solution
{
public:
    Solution()
    {}

    ~Solution()
    {}

    double minAreaFreeRect(std::vector<std::vector<int>>& points) {
        double res = std::numeric_limits<double>::max();
        
        size_t len = points.size();
        std::vector<Point*> ps(len, nullptr);
        for (int i = 0; i < len; i++) {
            ps[i] = new Point(points[i][0], points[i][1]);
            //std::cout << ps[i]->ToString() << std::endl; // debug
        }

        std::vector<Rect> rects;
        for (int i = 0; i < len; i++) {
            Point* p1 = ps[i];
            
            for (int j = 0; j < len; j++) {
                Point* p2 = ps[j];
                if (p2 != p1) {
                    //std::cout << "p1 = " << p1->ToString() << ", p2 = " << p2->ToString() << std::endl; // debug

                    Rect tmp = this->FindRectangle(p1, p2, ps);
                    if (tmp.IsCompleteRect()) {
                        rects.push_back(tmp);
                    }
                }
            }
        }

        for (auto r : rects) {
            double s1 = sqrt((r.Sides[0].X * r.Sides[0].X) + (r.Sides[0].Y * r.Sides[0].Y));
            double s2 = sqrt((r.Sides[1].X * r.Sides[1].X) + (r.Sides[1].Y * r.Sides[1].Y));
            double area = s1 * s2;
            //std::cout << "rectangle " << r.ToString() << ": s1 = " << s1 << ", s2 = " << s2 << ", area = " << area << std::endl; // debug
            if (area != 0 && res > area)
                res = area;
            
        }

        // avoid no find any rectangle
        if (res == std::numeric_limits<double>::max())
            res = 0;

        for (int i = 0; i < len; i++) {
            if (ps[i]) {
                delete ps[i];
                ps[i] = nullptr;
            }
        }
        return res;
    }

private:
    typedef struct _point
    {
        int X = 0;
        int Y = 0;

        _point(int x, int y)
        {
            this->X = x;
            this->Y = y;
        }

        _point ScaleWith(int scale)
        {
            _point ret(this->X, this->Y);
            ret.X = X * scale;
            ret.Y = Y * scale;
            return ret;
        }

        bool IsEqual(const _point r)
        {
            return (this->X == r.X) && (this->Y == r.Y);
        }

        std::string ToString()
        {
            std::ostringstream ss;
            ss << "[" << X << ", " << Y << "]";
            return ss.str();
        }
    } Point;
    typedef Point Vector;

    typedef struct _rect
    {
        std::vector<Vector> Sides;
        std::vector<Point*> Points;

        bool IsCompleteRect()
        {
            return (Sides.size() == 4);
        }

        std::string ToString()
        {
            std::ostringstream ss;
            ss << "[";
            for (auto const s : Sides)
                ss << " [" << s.X << ", " << s.Y << "]";
            ss << "]";

            return ss.str();
        }
    }Rect;

    int InnerProduct(Vector v1, Vector v2)
    {
        return (v1.X * v2.X) + (v1.Y * v2.Y);
    }

    Rect FindRectangle(Point* p1, Point* p2, std::vector<Point*> ps)
    {
        Rect res;
        res.Sides.push_back(Vector(p2->X - p1->X, p2->Y - p1->Y));
        Point* beginPoint = p1;

        std::unordered_map<Point*, bool> vsted;
        vsted[p1] = true;
        vsted[p2] = true;

        for (int i = 0; i < ps.size(); i++) {
            if (!vsted[ps[i]]) {
                Point* p3 = ps[i];
                int inrpd = InnerProduct (res.Sides.back(), Vector(p3->X - p2->X, p3->Y - p2->Y));
                //std::cout << "\tIn FindRectangle: p1 = " << p1->ToString() << ", p2 = " << p2->ToString() << ", p3 = " << p3->ToString() << ", inrpd = " << inrpd << std::endl; // debug
                if (inrpd == 0) {
                    res.Sides.push_back(Vector(p3->X - p2->X, p3->Y - p2->Y));
                    p1 = p2;
                    p2 = p3;
                }
                //std::cout << "\t\trect = " << res.ToString() << std::endl; // debug
            }

            if (res.Sides.size() == 3) {
                //std::cout << "\t\tfind a complete rectangle candidate!" << std::endl; // debug
                Vector lastSide = Vector(beginPoint->X - p2->X, beginPoint->Y - p2->Y);
                Vector opLastSide = lastSide.ScaleWith(-1);
                if (lastSide.IsEqual(res.Sides[1]) || opLastSide.IsEqual(res.Sides[1])) {
                   res.Sides.push_back(lastSide);
                   //std::cout << "\t\tfind a complete rectangle: " << res.ToString() << std::endl; // debug
                }
                break;
            }
        }
        
        return res;
    }

};

class TestMinAreaFreeRect
{
public:
	TestMinAreaFreeRect()
	{}

	~TestMinAreaFreeRect()
	{}

    void Example1()
    {
        std::cout << "Test input [[1,2],[2,1],[1,0],[0,1]] and minimum rectangle area = 2.0" << std::endl;
        std::vector<std::vector<int>> input({{1,2},{2,1},{1,0},{0,1}});

        double result = this->mSolution.minAreaFreeRect(input);

        AssertClass::GetInstance().Assert(IsTwoDoubleEqual(result, 2.0));
    }

    void Example2()
    {
        std::cout << "Test input [[0,1],[2,1],[1,1],[1,0],[2,0]] and minimum rectangle area = 1.0" << std::endl;;
        std::vector<std::vector<int>> input({{0,1},{2,1},{1,1},{1,0},{2,0}});

        double result = this->mSolution.minAreaFreeRect(input);

        AssertClass::GetInstance().Assert(IsTwoDoubleEqual(result, 1.0));
    }

    void Example3()
    {
        std::cout << "Test input [[0,3],[1,2],[3,1],[1,3],[2,1]] and minimum rectangle area = 0.0" << std::endl;;
        std::vector<std::vector<int>> input({{0,3},{1,2},{3,1},{1,3},{2,1}});

        double result = this->mSolution.minAreaFreeRect(input);

        AssertClass::GetInstance().Assert(IsTwoDoubleEqual(result, 0.0));
    }

    void BigRectangleIncludeSmallRectangle()
    {
        std::cout << "Test bigger rectangle include small rectangle: input [[0,0],[0,2],[1,0],[1,1],[2,2],[2,1],[2,0]]  and minimum rectangle area = 1.0" << std::endl;
        std::vector<std::vector<int>> input({{0,0},{0,2},{1,0},{1,1},{2,2},{2,1},{2,0}});

        double result = this->mSolution.minAreaFreeRect(input);

        AssertClass::GetInstance().Assert(IsTwoDoubleEqual(result, 1.0));
    }

    void ThreeSidePrependicularAndLastSideNot()
    {
        std::cout << "Test three side prependicular and last side not: input [[1,2], [3,2], [3,0], [0,0]]  and minimum rectangle area = 0.0" << std::endl;
        std::vector<std::vector<int>> input({{1,2}, {3,2}, {3,0}, {0,0}});

        double result = this->mSolution.minAreaFreeRect(input);

        AssertClass::GetInstance().Assert(IsTwoDoubleEqual(result, 0.0));
    }

    void Example4()
    {
        std::cout << "Test input [[3,1],[1,1],[0,1],[2,1],[3,3],[3,2],[0,2],[2,3]] and minimum rectangle area = 2.0" << std::endl;
        std::vector<std::vector<int>> input({{3,1},{1,1},{0,1},{2,1},{3,3},{3,2},{0,2},{2,3}});

        double result = this->mSolution.minAreaFreeRect(input);

        AssertClass::GetInstance().Assert(IsTwoDoubleEqual(result, 2.0));
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestMinAreaFreeRect test;
    test.Example1();
    test.Example2();
    test.Example3();
    test.BigRectangleIncludeSmallRectangle();
    test.ThreeSidePrependicularAndLastSideNot();
    test.Example4();
	getchar();
	return EXIT_SUCCESS;
}