#pragma once


// CDFDProgramerDialogModifyContent dialog

class CDFDProgramerDialogModifyContent : public CDialogEx
{
	DECLARE_DYNAMIC(CDFDProgramerDialogModifyContent)

public:
	CDFDProgramerDialogModifyContent(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDFDProgramerDialogModifyContent();
	int SetContent(const CString& content);
	CString &GetContent();
// Dialog Data
	enum { IDD = IDD_DIALOG_SETCONTENT };
private:
	CString Content;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
