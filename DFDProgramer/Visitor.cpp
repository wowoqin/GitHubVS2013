#include "stdafx.h"
#include "Visitor.h"


Visitor::Visitor() :state(0)
{
	state = 0;
	selected_item = NULL;
}


Visitor::~Visitor()
{
}


void Visitor::Init()
{
	state = 0;
}

void Visitor::CreateItem(CPoint& l_u)
{

	switch (state)
	{
	case 31:
	{
			   CreateFILE(l_u);
			   break;
	}
	case 32:
	{
			   CreateFUNCTION(l_u);
			   break;
	}
	case 33:
	{
			   CreateIO(l_u);
			   break;
	}
	case 34:
	{
			   CreateAND(l_u);
			   break;
	}
	case 35:
	{
			   CreateOR(l_u);
			   break;
	}
	case 36:
	{
			   CreateMILDOR(l_u);
			   break;
	}
	case 37:
	{
			   CreateSTRAIGHTFLOW(l_u);
			   break;
	}
	case 38:
	case 39:
	default:
	{
			   state = 10; break;
	}
	}
}


void Visitor::CreateFILE(CPoint& l_u)
{
	mgr.AddItem(mgr.AddDataFile(l_u));
}

void Visitor::CreateFUNCTION(CPoint& l_u)
{
	mgr.AddItem(mgr.AddDataFunction(l_u));
}

void Visitor::CreateIO(CPoint& l_u)
{
	mgr.AddItem(mgr.AddDataIO(l_u));
}


void Visitor::CreateAND(CPoint& l_u)
{
	mgr.AddItem(mgr.AddDataAnd(l_u));
}


void Visitor::CreateOR(CPoint& l_u)
{

	mgr.AddItem(mgr.AddDataOr(l_u)); 
}


void Visitor::CreateMILDOR(CPoint& l_u)
{
	mgr.AddItem(mgr.AddDataMildOr(l_u));
}


void Visitor::CreateSTRAIGHTFLOW(CPoint& l_u)
{
	mgr.AddItem(mgr.AddDataStraitghtFlow(l_u));
}


void Visitor::Draw(CDC* pDC)
{
	mgr.DrawItem(pDC);
}


void Visitor::MoveItem(CPoint& l_u)
{
	if (state<30 && state>=20)
	{
		mgr.MoveItem(l_u, selected_item);
		//state = 10;
	}
}


void Visitor::SelectedItem(CPoint& l_u)
{
	if (state<20 && state>= 10)
	{
		selected_item = mgr.SelectItem(l_u);
		if (selected_item != NULL)
			state = 20;
		else
			state = 10;
	}
}


void Visitor::DeleteItem()
{
	if (mgr.DeleteItem(mgr.SelectItem(press_point)) != 0)
		return;
	//if (selected_item!=NULL)

}


void Visitor::SetName( const CString& content)
{
	mgr.ModifyContent(content, mgr.SelectItem(press_point));
}


void Visitor::SignPos(const CPoint& point)
{
	press_point = point;
}


void Visitor::FormatState(const int &force_state)
{
	state = force_state;
}