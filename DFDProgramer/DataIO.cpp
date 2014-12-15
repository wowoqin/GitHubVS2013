#include "stdafx.h"
#include "DataIO.h"


CDataIO::CDataIO()
{
	Left_Up.x = 20;
	Left_Up.y = 30;
	Right_Down.x = 100;
	Right_Down.y = 100;
}


CDataIO::~CDataIO()
{
}


CDataIO::CDataIO(const LONG& left, const LONG& up, const LONG& right, const LONG& down) : CElement(left, up, right, down)
{

}


CDataIO::CDataIO(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString& content) : CElement(left, up, right, down, content)
{

}


CDataIO::CDataIO(const CPoint& l_u, const CPoint& r_d) : CElement(l_u, r_d)
{

}


CDataIO::CDataIO(const CPoint& l_u, const CPoint& r_d, const CString& content) : CElement(l_u, r_d, content)
{

}


void CDataIO::OnDraw(CDC* pDC)
{
	COLORREF color = RGB(255, 255, 255);
	CBrush brush(color);
	pDC->SelectObject(&brush);
	pDC->Rectangle(Left_Up.x, Left_Up.y, Right_Down.x, Right_Down.y);
	color = RGB(255, 255, 255);
	pDC->SelectObject(&brush);
	pDC->SetBkMode(0);
	pDC->TextOutW(Left_Up.x + 10, Left_Up.y + 10, Item_Content);
}


int CDataIO::SetContent(const CString &content)
{
	Item_Content = content;
	return 0;
}


CString &CDataIO::GetContent()
{
	return Item_Content;
}