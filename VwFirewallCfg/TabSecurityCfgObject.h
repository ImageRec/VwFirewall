#if !defined(AFX_TABSECURITYCFGOBJECT_H__95D7EAE3_2EF0_441A_9ADD_A8CC4F997840__INCLUDED_)
#define AFX_TABSECURITYCFGOBJECT_H__95D7EAE3_2EF0_441A_9ADD_A8CC4F997840__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TabSecurityCfgObject.h : header file
//
#include "TabSecurityCfgBase.h"



/////////////////////////////////////////////////////////////////////////////
// CTabSecurityCfgObject dialog

class CTabSecurityCfgObject : public CDialog
{
// Construction
public:
	CTabSecurityCfgObject(CWnd* pParent = NULL);   // standard constructor
	~CTabSecurityCfgObject();

public:
	VOID LoadDataFromCfgFile();
	VOID InitList();
	VOID DetectAclsProblems();

	VOID BackupRegister();
	VOID FixAclsProblems();
	VOID RecoverFixing();

private:
	static unsigned __stdcall _threadFixAclsProblems( PVOID arglist );
	VOID FixAclsProblemsProc();
	CDeThreadSleep m_cThSleepFixAclsProblems;
	BOOL m_bDoingFix;
	BOOL m_bFixInProgress;
	
	static unsigned __stdcall _threadRecoverFixing( PVOID arglist );
	VOID RecoverFixingProc();
	CDeThreadSleep m_cThSleepRecoverFixing;
	BOOL m_bDoingRecover;
	BOOL m_bRecoverInProgress;

public:
	TCHAR m_szRecoverRegCmdLine[ 1024 ];
	TCHAR m_szInfo[ MAX_PATH ];
	DWORD m_dwInfoType;

private:
	CTabSecurityCfgBase m_cTabSecurityCfgBase;
	CVwFirewallConfigFile m_cVwFirewallConfigFile;

	CParseCfgData m_CfgObjectData;
	CQueryAclsInfo m_cQueryAclsInfo;

public:
// Dialog Data
	//{{AFX_DATA(CTabSecurityCfgObject)
	enum { IDD = IDD_TAB_SECURITYCFG_OBJECT };
	CButtonST	m_btnRecover;
	CButtonST	m_btnDetect;
	CButtonST	m_btnFix;	
	CListCtrl	m_listGroup;
	CProgressCtrl	m_proBar;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTabSecurityCfgObject)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CTabSecurityCfgObject)
	virtual BOOL OnInitDialog();
	afx_msg void OnButtonDetect();
	afx_msg void OnButtonFix();
	afx_msg void OnButtonRecover();
	afx_msg void OnDblclkListGroup(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickListGroup(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnMenuListDetail();
	virtual LRESULT OnDoNext( WPARAM wParam, LPARAM lParam );
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TABSECURITYCFGOBJECT_H__95D7EAE3_2EF0_441A_9ADD_A8CC4F997840__INCLUDED_)
