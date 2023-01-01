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
        for (int i = 0; i < len; i++)
            ps[i] = new Point(points[i][0], points[i][1]);

        std::unordered_map<Point*, bool> visited;
        std::vector<Rect> rects;
        for (int i = 0; i < len; i++) {
            Point* p1 = ps[i];
            visited.insert(std::pair<Point*, bool>(p1, true));
            
            for (int j = 0; j < len; j++) {
                Point* p2 = ps[j];
                if (visited.find(p2) != visited.end() && !visited[p2]) {
                    Rect tmp = this->FindRectangle(p1, p2, ps, visited);
                    rects.push_back(tmp);
                }
            }
        }

        for (auto r : rects) {
            if (r.IsComplete()) {
                double s1 = sqrt((r.Sides[0].X * r.Sides[0].X) + (r.Sides[0].Y * r.Sides[0].Y));
                double s2 = sqrt((r.Sides[1].X * r.Sides[1].X) + (r.Sides[1].Y * r.Sides[1].Y));
                double area = s1 * s2;
                res = res > area ? area : res;
            }
        }

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
    } Point;
    typedef Point Vector;

    typedef struct _rect
    {
        std::vector<Vector> Sides;

        bool IsCompleteRect()
        {
            return (Sides.size() == 4);
        }
    }Rect;

    int InnerProduct(Vector v1, Vector v2)
    {
        return (v1.X * v2.X) + (v2.Y * v2.Y);
    }

    Rect FindRectangle(Point* p1, Point* p2, std::vector<Point*> ps, std::unordered_map<Point*, bool> vsted)
    {
        Rect res;
        res.Sides.push_back(Vector(p2->X - p1->X, p2->Y - p1->Y));
        Point* beginPoint = p1;

        vsted[p1] = true;
        vsted[p2] = true;

        for (int i = 0; i < ps.size(); i++) {
            if (!vsted[ps[i]]) {
                Point* p3 = ps[i];
                int inrpd = InnerProduct (Vector(p2->X - p1->X, p2->X - p1->Y), Vector(p3->X - p2->X, p3->Y - p2->Y);
                if (inrpd == 0) {
                    res.Sides.push_back(Vector(p3->X - p2->X, p3->Y - p2->Y));
                    p1 = p2;
                    p2 = p3;
                }
            }

            if (res.Sides.size() == 3) {
                Vector lastSide = Vector(beginPoint->X - p2->X, beginPoint->Y - p2->Y);
                if (InnerProduct(res.Sides[0], lastSide) == -1) {
                   res.Sides.push_back(lastSide);
                }
                break;
            }
        }
        
        return res;
    }   

};

class TestValidUtf8
{
public:
	TestValidUtf8()
	{}

	~TestValidUtf8()
	{}

    void Input_197_130_1_Output_true()
    {
        std::cout << "Test input [197,130,1] and output true" << std::endl;;
        std::vector<int> input({197, 130, 1});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == true);
    }

    void Input_235_140_4_Output_false()
    {
        std::cout << "Test input [235,140,4] and output false" << std::endl;;
        std::vector<int> input({235,140,4});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == false);
    }

    void Input_237_Output_false()
    {
        std::cout << "Test input [237] and output false" << std::endl;;
        std::vector<int> input({237});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == false);
    }

    void Input_230_136_145_Output_true()
    {
        std::cout << "Test input [230,136,145] and output true" << std::endl;;
        std::vector<int> input({230,136,145});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == true);
    }

    void Input_145_Output_false()
    {
        std::cout << "Test input [145] and output false" << std::endl;;
        std::vector<int> input({145});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == false);
    }

    void Input_240_162_138_147_Output_true()
    {
        std::cout << "Test input [240, 162, 138, 147] and output true" << std::endl;;
        std::vector<int> input({240, 162, 138, 147});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == true);
    }

    void Input_248_130_130_130_Output_true()
    {
        std::cout << "Test input [240, 162, 138, 147] and output true" << std::endl;;
        std::vector<int> input({240, 162, 138, 147});

        bool result = this->mSolution.validUtf8(input);

        AssertClass::GetInstance().Assert(result == true);
    }

private:
	Solution mSolution;

};

int main(int argc, char** argv)
{
	TestValidUtf8 test;
    test.Input_197_130_1_Output_true();
    test.Input_235_140_4_Output_false();
    test.Input_237_Output_false();
    test.Input_230_136_145_Output_true();
    test.Input_145_Output_false();
    test.Input_240_162_138_147_Output_true();
    test.Input_248_130_130_130_Output_true();
	getchar();
	return EXIT_SUCCESS;
}