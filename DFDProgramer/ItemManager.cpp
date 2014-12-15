#include "stdafx.h"
#include "ItemManager.h"


CItemManager::CItemManager() 
{
	elem_it = elem_list.begin();
	flow_it = flow_list.begin();
}


CItemManager::~CItemManager()
{
	elem_list.clear();
	flow_list.clear();
}


CElement* CItemManager::AddDataFile(const CPoint& l_u)
{
	CDataFile *tmp_file = new CDataFile(l_u.x,l_u.y,l_u.x+50,l_u.y+50);
	return tmp_file;
}


CElement* CItemManager::AddDataFunction(const CPoint& l_u)
{
	CDataFunction *tmp_function = new CDataFunction(l_u.x, l_u.y, l_u.x + 50, l_u.y + 50);
	return tmp_function;
}


CElement* CItemManager::AddDataIO(const CPoint& l_u)
{
	CDataIO *tmp_IO = new CDataIO(l_u.x, l_u.y, l_u.x + 50, l_u.y + 50);
	return tmp_IO;
}

CElement* CItemManager::AddDataAnd(const CPoint& l_u)
{
	CDataAnd *tmp_And = new CDataAnd(l_u.x, l_u.y, l_u.x+10, l_u.y+10);
	return tmp_And;
}

CElement* CItemManager::AddDataOr(const CPoint& l_u)
{
	CDataOr *tmp_Or = new CDataOr(l_u.x, l_u.y, l_u.x+10, l_u.y+10);
	return tmp_Or;
}

CElement* CItemManager::AddDataMildOr(const CPoint& l_u)
{
	CDataMildOr *tmp_MildOr = new CDataMildOr(l_u.x, l_u.y, l_u.x+10, l_u.y+10);
	return tmp_MildOr;
}


int CItemManager::AddItem(CElement* elem)
{
	elem_list.push_back(elem);
	return 0;
}


CFlow* CItemManager::AddDataStraitghtFlow(const CPoint& l_u)
{
	CDataStraightFlow* tmp_straight_flow = new CDataStraightFlow(l_u.x, l_u.y, l_u.x + 50, l_u.y + 50);
	return tmp_straight_flow;
}


int CItemManager::AddItem(CFlow* flow)
{
	flow_list.push_back(flow);
	return 0;
}


int CItemManager::DeleteItem(CElement* elem)
{
	elem_it = elem_list.begin();
	while ((*elem_it) != elem)
		elem_it++;
	if (elem_it == elem_list.end())
		return 1;
	elem_list.erase(elem_it);
	return 0;
}


int CItemManager::DeleteItem(CItem* item)
{
	elem_it = elem_list.begin();
	flow_it = flow_list.begin();
	while ((*elem_it) != item)
		elem_it++;
	if (elem_it == elem_list.end())
	{
		while ((*flow_it) != item)
			flow_it++;
		if (flow_it == flow_list.end())
			return 1;
		elem_list.erase(elem_it);
		return 0;
	}
	elem_list.erase(elem_it);
	return 0;
}


int CItemManager::ModifyContent(const CString& content, CElement* elem)
{
	elem_it = elem_list.begin();
	while ((*elem_it) != elem)
		elem_it++;
	if (elem_it == elem_list.end())
		return 1;
	(*elem_it)->SetContent(content);
	return 0;
}


int CItemManager::ModifyContent(const CString& content, CFlow* flow)
{
	flow_it = flow_list.begin();
	while ((*flow_it) != flow)
		flow_it++;
	if (flow_it == flow_list.end())
		return 1;
	(*flow_it)->SetContent(content);
	return 0;
}


int CItemManager::ModifyContent(const CString& content, CItem* item)
{
	elem_it = elem_list.begin();
	flow_it = flow_list.begin();
	while ((*elem_it) != item)
		elem_it++;
	if (elem_it == elem_list.end())
	{
		while ((*flow_it) != item)
			flow_it++;
		if (flow_it == flow_list.end())
			return 1;
		(*flow_it)->SetContent(content);
		return 0;
	}
	(*elem_it)->SetContent(content);
	return 0;
	
}


CElement* CItemManager::SelectElement(const CPoint& point)
{
	elem_it = elem_list.begin();
	for (size_t counter = 0; counter < elem_list.size(); ++counter)
	{
		if ((*elem_it)->GetLeftEdge()<point.x && (*elem_it)->GetTopEdge() < point.y && (*elem_it)->GetBottomEdge() > point.y && (*elem_it)->GetRightEdge() >point.x)
			return (*elem_it);
		elem_it++;
	}
	return NULL;
}


CFlow* CItemManager::SelectFlow(const CPoint& point)
{
	flow_it = flow_list.begin();
	for (size_t counter = 0; counter < flow_list.size(); ++counter)
	{
		if ((*flow_it)->GetLeftEdge()<point.x && (*flow_it)->GetTopEdge() < point.y && (*flow_it)->GetBottomEdge() > point.y && (*flow_it)->GetRightEdge() >point.x)
			return (*flow_it);
		flow_it++;
	}
	return NULL;
}


CItem* CItemManager::SelectItem(const CPoint& point)
{
	elem_it = elem_list.begin();
	flow_it = flow_list.begin();
	for (size_t counter = 0; counter < elem_list.size(); ++counter)
	{
		if ((*elem_it)->GetLeftEdge()<point.x && (*elem_it)->GetTopEdge() < point.y && (*elem_it)->GetBottomEdge() > point.y && (*elem_it)->GetRightEdge() >point.x)
			return (*elem_it);
		elem_it++;
	}
	for (size_t counter = 0; counter < flow_list.size(); ++counter)
	{
		if ((*flow_it)->GetLeftEdge()<point.x && (*flow_it)->GetTopEdge() < point.y && (*flow_it)->GetBottomEdge() > point.y && (*flow_it)->GetRightEdge() >point.x)
			return (*flow_it);
		flow_it++;
	}
	return NULL;
}


int CItemManager::MoveItem(const CPoint& new_point, CItem* selected_item)
{
	selected_item->SetLeftEdge(new_point.x);
	selected_item->SetTopEdge(new_point.y);
	selected_item->SetRightEdge(new_point.x + 50);
	selected_item->SetBottomEdge(new_point.y + 50);
	return 0;
}


int CItemManager::DrawItem(CDC* pDC)
{
	elem_it = elem_list.begin();
	while (elem_it != elem_list.end())
	{
		(*elem_it)->OnDraw(pDC);
		elem_it++;
	}
	flow_it = flow_list.begin();
	while (flow_it != flow_list.end())
	{
		(*flow_it)->OnDraw(pDC);
		flow_it++;
	}

	return 0;
}