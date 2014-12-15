
// DFDProgramerDoc.h : interface of the CDFDProgramerDoc class
//
#include "ItemManager.h"
#include "Visitor.h"
#pragma once

#define IDB_BUTTON_AND 130
#define IDB_BUTTON_OR 131
#define IDB_BUTTON_MILDOR 132

class CDFDProgramerDoc : public CDocument
{
protected: // create from serialization only
	CDFDProgramerDoc();
	DECLARE_DYNCREATE(CDFDProgramerDoc)

// Attributes
public:
	Visitor visitor;
// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CDFDProgramerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
