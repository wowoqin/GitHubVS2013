#include "stdafx.h"
#include "DataFile.h"


CDataFile::CDataFile()
{
	Left_Up.x=20;
	Left_Up.y=30;
	Right_Down.x=100;
	Right_Down.y=100;
}


CDataFile::~CDataFile()
{
}


CDataFile::CDataFile(const LONG& left, const LONG& up, const LONG& right, const LONG& down) : CElement(left,up,right,down)
{

}


CDataFile::CDataFile(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString& content) : CElement(left, up, right, down, content)
{

}


CDataFile::CDataFile(const CPoint& l_u, const CPoint& r_d) : CElement(l_u, r_d)
{

}


CDataFile::CDataFile(const CPoint& l_u, const CPoint& r_d, const CString& content) : CElement(l_u, r_d, content)
{

}


void CDataFile::OnDraw(CDC* pDC)
{
	COLORREF color = RGB(255, 255, 255);
	CBrush brush(color);
	pDC->SelectObject(&brush);
	pDC->MoveTo(Left_Up.x, Right_Down.y);
	pDC->LineTo(Right_Down.x, Right_Down.y);
	pDC->MoveTo(Left_Up.x, Right_Down.y-5);
	pDC->LineTo(Right_Down.x, Right_Down.y-5);
	color = RGB(255, 255, 255);
	pDC->SelectObject(&brush);
	pDC->SetBkMode(0);
	pDC->TextOutW(Left_Up.x + 20, Left_Up.y + 25, Item_Content);
}


int CDataFile::SetContent(const CString &content)
{
	Item_Content = content;
	return 0;
}


CString &CDataFile::GetContent()
{
	return Item_Content;
}