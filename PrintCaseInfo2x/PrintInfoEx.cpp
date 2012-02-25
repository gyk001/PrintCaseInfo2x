// PrintInfoEx.cpp : 实现文件
//

#include "stdafx.h"
#include "PrintCaseInfo2x.h"
#include "PrintInfoEx.h"


// CPrintInfoEx

CPrintInfoEx::CPrintInfoEx()
{
    resetCur();
}

CPrintInfoEx::~CPrintInfoEx()
{
}


// CPrintInfoEx 成员函数
CPrintInfoEx::CPrintInfoEx(CRect rc,bool horizontal)
{
    this->rc=rc;
    this->horizontal=horizontal;
    cur=(rc.left,rc.top);
}
void CPrintInfoEx::setRect(CRect rc)
{
    this->rc=rc;
    resetCur();
}

void CPrintInfoEx::setRectWidth(int width)
{
    rc.right=rc.left+width;
}
void CPrintInfoEx::setRectHeight(int height)
{
    rc.bottom=rc.top-height;
}
void CPrintInfoEx::MoveCurTo(int x,int y)
{
    cur.x=x;
    cur.y=y;
}
// void CPrintInfoEx::MoveOffset(int x,int y)
// {
//     rc.left+=x;
//     rc.top=rc.bottom-y;
//     rc.right+=x;
//     rc.bottom-=y;
//    resetCur();
// }

void CPrintInfoEx::MoveDown()
{
    rc.top=rc.bottom;
    resetCur();
}

void CPrintInfoEx::MoveRight()
{
    rc.left=rc.right;
    resetCur();
}

void CPrintInfoEx::MoveLeft()
{
    rc.right=rc.left;
    resetCur();
}

void CPrintInfoEx::setLeft(int left)
{
    rc.left=left;
    resetCur();
}

void CPrintInfoEx::SetRight(int right)
{
    rc.right=right;
    resetCur();
}

void CPrintInfoEx::SetBottom(int bottom)
{
    rc.bottom=bottom;
    resetCur();
}

void CPrintInfoEx::SetTop(int top)
{
    rc.top=top;
    resetCur();
}


void CPrintInfoEx::resetCur()
{
    cur=rc.TopLeft();
}

void CPrintInfoEx::drawBox(CDC* pDC)
{
    CRect tmp =rc;
    tmp.NormalizeRect();
    pDC->Rectangle(tmp);

}
