
// DFDProgramerView.h : interface of the CDFDProgramerView class
//
#include "DFDProgramerDialogModifyContent.h"
#pragma once


class CDFDProgramerView : public CView
{
protected: // create from serialization only
	CDFDProgramerView();
	DECLARE_DYNCREATE(CDFDProgramerView)

// Attributes
public:
	CDFDProgramerDoc* GetDocument() const;

// Operations
public:
	CButton m_button;
	CButton m_button_and;
	CButton m_button_or;
	CButton m_button_mildor;
	CComboBox m_elem;
	CComboBox m_rela;
	CComboBox m_flow;
	CMenu m_right_button;//ÓÒ¼ü²Ëµ¥
	CDFDProgramerDialogModifyContent m_dlg_set_content;
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CDFDProgramerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnButtonClickTEST();
	afx_msg void OnButtonClickAND();
	afx_msg void OnButtonClickOR();
	afx_msg void OnButtonClickMILDOR();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnSetName();
	afx_msg void OnDeleteItem();
	afx_msg void OnComboBoxElemSelChange();
	afx_msg void OnComboBoxRelaSelChange();
	afx_msg void OnComboBoxFlowSelChange();
};

#ifndef _DEBUG  // debug version in DFDProgramerView.cpp
inline CDFDProgramerDoc* CDFDProgramerView::GetDocument() const
   { return reinterpret_cast<CDFDProgramerDoc*>(m_pDocument); }
#endif

