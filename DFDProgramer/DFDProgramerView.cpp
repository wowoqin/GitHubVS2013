
// DFDProgramerView.cpp : implementation of the CDFDProgramerView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "DFDProgramer.h"
#endif

#include "DFDProgramerDoc.h"
#include "DFDProgramerView.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDFDProgramerView

IMPLEMENT_DYNCREATE(CDFDProgramerView, CView)

BEGIN_MESSAGE_MAP(CDFDProgramerView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CDFDProgramerView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CREATE()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_TEST, OnButtonClickTEST)
	ON_BN_CLICKED(IDB_BUTTON_AND, OnButtonClickAND)
	ON_BN_CLICKED(IDB_BUTTON_OR, OnButtonClickOR)
	ON_BN_CLICKED(IDB_BUTTON_MILDOR, OnButtonClickMILDOR)
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_32771, &CDFDProgramerView::OnSetName)
	ON_COMMAND(ID_32772, &CDFDProgramerView::OnDeleteItem)
	ON_CBN_SELCHANGE(IDC_COMBOBOX_ELEM, &CDFDProgramerView::OnComboBoxElemSelChange)
	ON_CBN_SELCHANGE(IDC_COMBOBOX_RELA, &CDFDProgramerView::OnComboBoxRelaSelChange)
	ON_CBN_SELCHANGE(IDC_COMBOBOX_FLOW, &CDFDProgramerView::OnComboBoxFlowSelChange)
END_MESSAGE_MAP()

// CDFDProgramerView construction/destruction

CDFDProgramerView::CDFDProgramerView()
{
	// TODO: add construction code here
	m_right_button.LoadMenuW(IDR_MENU_DFDP);
}

CDFDProgramerView::~CDFDProgramerView()
{
}

BOOL CDFDProgramerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CDFDProgramerView drawing

void CDFDProgramerView::OnDraw(CDC* pDC)
{
	CDFDProgramerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDoc->visitor.Draw(pDC);
	// TODO: add draw code for native data here
}


// CDFDProgramerView printing


void CDFDProgramerView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CDFDProgramerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CDFDProgramerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CDFDProgramerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CDFDProgramerView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	CDFDProgramerDoc* pDoc = GetDocument();
	pDoc->visitor.SignPos(point);
	ClientToScreen(&point);
	OnContextMenu(this, point);

}

void CDFDProgramerView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
//#ifndef SHARED_HANDLERS
//	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
//#endif
//	CPoint p;
//	GetCursorPos(&p);
	CMenu *m_SubMenu = m_right_button.GetSubMenu(0);
	m_SubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, point.x, point.y, this);

}


// CDFDProgramerView diagnostics

#ifdef _DEBUG
void CDFDProgramerView::AssertValid() const
{
	CView::AssertValid();
}

void CDFDProgramerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDFDProgramerDoc* CDFDProgramerView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDFDProgramerDoc)));
	return (CDFDProgramerDoc*)m_pDocument;
}
#endif //_DEBUG


// CDFDProgramerView message handlers


int CDFDProgramerView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	CRect rect_button(40, 10, 200, 60);
	CRect rect_combobox_elem(300, 10, 450, 60);
	CRect rect_combobox_flow(500, 10, 650, 60);
	CRect rect_conbobox_rela(700, 10, 850, 60);
	CRect rect_button_and(40, 110, 100, 160);    //描述控件位置以及大小的结构
	CRect rect_button_or(120, 110, 180, 160);    //描述控件位置以及大小的结构
	CRect rect_button_mildor(200, 110, 260, 160);    //描述控件位置以及大小的结构
	m_elem.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, rect_combobox_elem, this, IDC_COMBOBOX_ELEM);
	m_rela.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, rect_conbobox_rela, this, IDC_COMBOBOX_RELA);
	m_flow.Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWNLIST, rect_combobox_flow, this, IDC_COMBOBOX_FLOW);
	m_button_mildor.Create(_T("异或"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect_button_mildor, this, IDB_BUTTON_MILDOR);
	m_button_or.Create(_T("或"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect_button_or, this, IDB_BUTTON_OR);
	m_button_and.Create(_T("与"), WS_CHILD | WS_VISIBLE | WS_BORDER, rect_button_and, this, IDB_BUTTON_AND);
	m_elem.InsertString(0, L"--Please select.--");
	m_elem.InsertString(1 , L"File");
	m_elem.InsertString(2 , L"Function");
	m_elem.InsertString(3 , L"Input/Output");
	m_rela.InsertString(0, L"--Please select.--");
	m_rela.InsertString(1, L"AND(+)");
	m_rela.InsertString(2, L"OR(*)");
	m_rela.InsertString(3, L"XOR(⊕)"); 
	m_flow.InsertString(0, L"--Please select.--");
	m_flow.InsertString(1, L"ARROW(->)");
	m_elem.SetCurSel(0);
	m_flow.SetCurSel(0);
	m_rela.SetCurSel(0);
	// TODO:  Add your specialized creation code here
	m_button.Create(L"test", WS_CHILD | WS_VISIBLE | WS_BORDER, rect_button, this, IDC_BUTTON_TEST);
	m_button_and.ShowWindow(SW_SHOWNORMAL);
	m_button_or.ShowWindow(SW_SHOWNORMAL);
	m_button_mildor.ShowWindow(SW_SHOWNORMAL);
	return 0;
}


void CDFDProgramerView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	CView::OnLButtonDblClk(nFlags, point);
}


void CDFDProgramerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDFDProgramerDoc* pDoc = GetDocument();
	pDoc->visitor.SelectedItem(point);
	this->Invalidate();
	CView::OnLButtonDown(nFlags, point);
}


void CDFDProgramerView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CDFDProgramerDoc* pDoc = GetDocument();
	//pDoc->visitor.MoveItem(point);
	pDoc->visitor.CreateItem(point);
	pDoc->visitor.FormatState(10);
	this->Invalidate(1);
	CView::OnLButtonUp(nFlags, point);
}


void CDFDProgramerView::OnButtonClickTEST()
{
	CDFDProgramerDoc* pDoc = GetDocument();
	pDoc->visitor.FormatState(1);
	this->Invalidate(1);
}

void CDFDProgramerView::OnButtonClickAND()
{
	CDFDProgramerDoc* pDoc = GetDocument();
	pDoc->visitor.FormatState(32);
	this->Invalidate(1);
}

void CDFDProgramerView::OnButtonClickOR()
{
	CDFDProgramerDoc* pDoc = GetDocument();
	pDoc->visitor.FormatState(33);
	this->Invalidate(1);
}

void CDFDProgramerView::OnButtonClickMILDOR()
{
	CDFDProgramerDoc* pDoc = GetDocument();
	pDoc->visitor.FormatState(34);
	this->Invalidate(1);
}

void CDFDProgramerView::OnMouseMove(UINT nFlags, CPoint point)
{

	CDFDProgramerDoc* pDoc = GetDocument();
	pDoc->visitor.MoveItem(point);
	this->Invalidate();
	// TODO: Add your message handler code here and/or call default
	CView::OnMouseMove(nFlags, point);
}


void CDFDProgramerView::OnSetName()
{
	//m_dlg_set_content.DoModal();
	CDFDProgramerDoc* pDoc = GetDocument();
	
	if (m_dlg_set_content.DoModal() == IDOK)
	{
		pDoc->visitor.SetName(m_dlg_set_content.GetContent());
	}
	this->Invalidate();
	// TODO: Add your command handler code here
}


void CDFDProgramerView::OnDeleteItem()
{
	CDFDProgramerDoc* pDoc = GetDocument();
	pDoc->visitor.DeleteItem();
	this->Invalidate();
	// TODO: Add your command handler code here
}


void CDFDProgramerView::OnComboBoxElemSelChange()
{
	CDFDProgramerDoc* pDoc = GetDocument();
	
	m_rela.SetCurSel(0);
	m_flow.SetCurSel(0);
	switch(m_elem.GetCurSel())
	{
	case 1:
		MessageBox(L"You Select the FILE!");
		pDoc->visitor.FormatState(31);
		break;
	case 2:
		MessageBox(L"You Select the FUNCTION!");
		pDoc->visitor.FormatState(32);
		break;
	case 3:
		MessageBox(L"You Select the IO!");
		pDoc->visitor.FormatState(33);
		break;
	case 0:
	default:
		MessageBox(L"Get some, Dude?");
		pDoc->visitor.FormatState(10);
		break;
	}
}


void CDFDProgramerView::OnComboBoxRelaSelChange()
{
	CDFDProgramerDoc* pDoc = GetDocument();
	m_elem.SetCurSel(0);
	m_flow.SetCurSel(0);
	switch (m_rela.GetCurSel())
	{
	case 1:
		MessageBox(L"You Select the AND!");
		pDoc->visitor.FormatState(34);
		break;
	case 2:
		MessageBox(L"You Select the OR!");
		pDoc->visitor.FormatState(35);
		break;
	case 3:
		MessageBox(L"You Select the XOR!");
		pDoc->visitor.FormatState(36);
		break;
	case 0:
	default:
		MessageBox(L"Get some, Dude?");
		pDoc->visitor.FormatState(10);
		break;
	}
}


void CDFDProgramerView::OnComboBoxFlowSelChange()
{
	CDFDProgramerDoc* pDoc = GetDocument();
	m_rela.SetCurSel(0);
	m_elem.SetCurSel(0);
	switch (m_flow.GetCurSel())
	{
	case 1:
		MessageBox(L"You Select the STRAIGHTFLOW!");
		pDoc->visitor.FormatState(37);
		break;
	case 2:
	case 3:
	case 0:
	default:
		MessageBox(L"Get some, Dude?");
		pDoc->visitor.FormatState(10);
		break;
	}
}