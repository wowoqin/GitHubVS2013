#include "stdafx.h"
#include "Flow.h"


CFlow::CFlow()
{
}


CFlow::~CFlow()
{
}


CFlow::CFlow(const LONG& left, const LONG& up, const LONG& right, const LONG& down) : CItem(left, up, right, down)
{

}


CFlow::CFlow(const LONG& left, const LONG& up, const LONG& right, const LONG& down, const CString& content) : CItem(left, up, right, down, content)
{

}


CFlow::CFlow(const CPoint& l_u, const CPoint& r_d) :CItem(l_u, r_d)
{

}


CFlow::CFlow(const CPoint& l_u, const CPoint& r_d, const CString& content) : CItem(l_u, r_d, content)
{

}