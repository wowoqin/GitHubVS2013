#include "stdafx.h"
#include "Element.h"


CElement::CElement()
{
}


CElement::~CElement()
{
}


CElement::CElement(const LONG& left, const LONG& up, const LONG& right, const LONG& down) : CItem(left,up,right,down)
{

}


CElement::CElement(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString& content) : CItem(left,up,right,down,content)
{

}


CElement::CElement(const CPoint& l_u, const CPoint& r_d) :CItem(l_u, r_d)
{

}
CElement::CElement(const CPoint& l_u, const CPoint& r_d, const CString& content) : CItem(l_u, r_d, content)
{

}