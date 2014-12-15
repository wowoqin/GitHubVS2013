#pragma once
class CItem
{
public:
	CItem();
	~CItem();
	CItem(const LONG& left, const LONG& up, const LONG& right, const LONG& down);
	CItem(const CPoint& l_u,const CPoint& r_d);
	CItem(const LONG& left, const LONG& up, const LONG& right, const LONG& down,const CString &content);
	CItem(const CPoint& l_u, const CPoint& r_d, const CString &content);
public:
	virtual void OnDraw(CDC* pDC);
	int SetContent(const CString &content);
	CString &GetContent();
	virtual LONG &GetLeftEdge();
	virtual LONG &GetRightEdge();
	virtual LONG &GetTopEdge();
	virtual LONG &GetBottomEdge();
	virtual int SetLeftEdge(const LONG& left);
	virtual int SetRightEdge(const LONG& right);
	virtual int SetTopEdge(const LONG& up);
	virtual int SetBottomEdge(const LONG& down);
protected:
	CString Item_Content;
	CPoint Left_Up;			//左上方的点
	CPoint Right_Down;		//右下方的点
};

