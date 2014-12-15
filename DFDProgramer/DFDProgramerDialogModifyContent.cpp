// DFDProgramerDialogModifyContent.cpp : implementation file
//

#include "stdafx.h"
#include "DFDProgramer.h"
#include "DFDProgramerDialogModifyContent.h"
#include "afxdialogex.h"


// CDFDProgramerDialogModifyContent dialog

IMPLEMENT_DYNAMIC(CDFDProgramerDialogModifyContent, CDialogEx)

CDFDProgramerDialogModifyContent::CDFDProgramerDialogModifyContent(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDFDProgramerDialogModifyContent::IDD, pParent)
{

}

CDFDProgramerDialogModifyContent::~CDFDProgramerDialogModifyContent()
{
}

void CDFDProgramerDialogModifyContent::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDFDProgramerDialogModifyContent, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDFDProgramerDialogModifyContent::OnBnClickedOk)
END_MESSAGE_MAP()


// CDFDProgramerDialogModifyContent message handlers


void CDFDProgramerDialogModifyContent::OnBnClickedOk()
{
	this->GetDlgItemTextW(IDC_EDIT_CONTENT, Content);
	if (Content.IsEmpty())
	{
		AfxMessageBox(L"Empty Content!!!");
		return;
	}
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


int CDFDProgramerDialogModifyContent::SetContent(const CString& content)
{
	Content = content;
	if (content.IsEmpty())
	{
		Content = L"Empty!";
		return 1;
	}
	return 0;

}
CString &CDFDProgramerDialogModifyContent::GetContent()
{
	return Content;
}