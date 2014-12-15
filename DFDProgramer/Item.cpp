#include "stdafx.h"
#include "Item.h"


CItem::CItem() :Item_Content(L"Untitle")
{
}


CItem::~CItem()
{
}

CItem::CItem(const LONG& left, const LONG& up, const LONG& right, const LONG& down) :Item_Content(L"Untitle")
{
	Left_Up.x = left;
	Left_Up.y = up;
	Right_Down.x = right;
	Right_Down.y = down;
}


CItem::CItem(const CPoint& l_u, const CPoint& r_d) :Item_Content(L"Untitle")
{
	Left_Up = l_u;
	Right_Down = r_d;
}


CItem::CItem(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString &content)
{
	Left_Up.x = left;
	Left_Up.y = up;
	Right_Down.x = right;
	Right_Down.y = down;
	Item_Content = content;
}


CItem::CItem(const CPoint& l_u, const CPoint& r_d, const CString &content)
{
	Left_Up = l_u;
	Right_Down = r_d;
	Item_Content = content;
}


void CItem::OnDraw(CDC* pDC)
{
	pDC->TextOutW(1,1,L"Wrong Instance.");
}


int CItem::SetContent(const CString &content)
{
	Item_Content = content;
	return 0;
}


CString &CItem::GetContent()
{
	return Item_Content;
}


LONG &CItem::GetLeftEdge()
{
	return Left_Up.x;
}


LONG &CItem::GetRightEdge()
{
	return Right_Down.x;
}


LONG &CItem::GetTopEdge()
{
	return Left_Up.y;
}


LONG &CItem::GetBottomEdge()
{
	return Right_Down.y;
}


int CItem::SetLeftEdge(const LONG& left)
{
	Left_Up = left;
	return 0;
}


int CItem::SetRightEdge(const LONG& right)
{
	Right_Down.x = right;
	return 0;
}


int CItem::SetTopEdge(const LONG& up)
{
	Left_Up.y = up;
	return 0;
}


int CItem::SetBottomEdge(const LONG& down)
{
	Right_Down.y = down;
	return 0;
}