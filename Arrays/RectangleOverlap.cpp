/* Rectangle that is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinates of its 
top-left corner, and (x2, y2) is the coordinates of its bottam-right corner. Now two rectangles overlap 
if the area of their intersection is positive.Two rectangles that only touch at the corner or edges do 
not overlap.Check in O(1) Time complexity and O(1) Space complexity that both rectangle overlap or not */

#include<iostream>
class Point
{
    public:
    int x,y;
    void setxy(int a,int b)
    {
        x = a;
        y = b;
    }
};
bool rectangleOverlap(Point rec1_tleft,Point rec1_bright,Point rec2_tleft,Point rec2_bright)
{
    if(rec1_tleft.x<rec2_bright.x && rec1_bright.y<rec2_tleft.y && rec1_tleft.y>rec2_bright.y)
        return true;
    else if(rec1_bright.x>rec2_tleft.x && rec1_bright.y<rec2_tleft.y && rec1_tleft.y>rec2_bright.y)
        return true;
    return false;
}
int main()
{
    int a,b;
    Point rec1_tleft,rec2_tleft,rec1_bright,rec2_bright;
    std::cout<<"Enter top left coordinate of 1st Rect:"<<std::endl;
    std::cin>>a>>b;
    rec1_tleft.setxy(a,b);
    std::cout<<"Enter bottom right coordinate of 1st Rect:"<<std::endl;
    std::cin>>a>>b;
    rec1_bright.setxy(a,b);

    std::cout<<"Enter top left coordinate of 2nd Rect:"<<std::endl;
    std::cin>>a>>b;
    rec2_tleft.setxy(a,b);
    std::cout<<"Enter bottom right coordinate of 2nd Rect:"<<std::endl;
    std::cin>>a>>b;
    rec2_bright.setxy(a,b);
    if(rectangleOverlap(rec1_tleft,rec1_bright,rec2_tleft,rec2_bright) == true)
        std::cout<<"Rectangle Overlap";
    else
        std::cout<<"Rectangle does not Overlap";
    return 0;
}