#pragma once

// CPrintInfoEx ÃüÁîÄ¿±ê

class CPrintInfoEx : public CObject
{
public:
	CPrintInfoEx();
	virtual ~CPrintInfoEx();
public:
    CRect rc;
    CPoint cur;
    bool horizontal;

    CPrintInfoEx(CRect rc,bool horizontal=true);
    void setRect(CRect tc);
    void setRectWidth(int width);
    void setRectHeight(int height);
    void MoveCurTo(int x,int y);
   // void MoveOffset(int x,int y);
    void MoveDown();
    void MoveRight();
    void MoveLeft();
    void setLeft(int left);
    void SetRight(int right);
    void SetBottom(int bottom);
   void SetTop(int top);
    void resetCur();
    void drawBox(CDC* pDC);
 };


