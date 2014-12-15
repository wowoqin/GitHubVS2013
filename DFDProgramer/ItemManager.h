#pragma once
#include <list>
#include "Item.h"
#include "DataFile.h"
#include "DataFunction.h"
#include "DataIO.h"
#include "DataAnd.h"
#include "DataOr.h"
#include "DataMildOr.h"
#include "DataStraightFlow.h"
class CItemManager
{
public:
	CItemManager();
	~CItemManager();
	int AddItem(CElement* item);
	int AddItem(CFlow* flow);
	int DeleteItem(CElement* item);
	int DeleteItem(CFlow* item);
	int DeleteItem(CItem* item);
	int ModifyContent(const CString& content, CElement* item);
	int ModifyContent(const CString& content, CFlow* flow);
	int ModifyContent(const CString& content, CItem* item);
	CElement* AddDataFile(const CPoint& l_u);
	CFlow* AddDataStraitghtFlow(const CPoint& l_u);
	CElement* AddDataFunction(const CPoint& l_u);
	CElement* AddDataIO(const CPoint& l_u);
	CElement* AddDataAnd(const CPoint& l_u);
	CElement* AddDataOr(const CPoint& l_u);
	CElement* AddDataMildOr(const CPoint& l_u);
	int MoveItem(const CPoint& new_point, CItem* selected_item);
	CElement* SelectElement(const CPoint& point);
	CFlow* SelectFlow(const CPoint& point);
	CItem* SelectItem(const CPoint& point);
	int DrawItem(CDC* pDC);
private:
	std::list<CFlow*> flow_list;
	std::list<CFlow*>::iterator flow_it;
	std::list<CElement*> elem_list;
	std::list<CElement*>::iterator elem_it;
	
};

