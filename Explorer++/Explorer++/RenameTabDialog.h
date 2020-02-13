// Copyright (C) Explorer++ Project
// SPDX-License-Identifier: GPL-3.0-only
// See LICENSE in the top level directory

#pragma once

#include "TabContainer.h"
#include "../Helper/BaseDialog.h"
#include "../Helper/DialogSettings.h"

class RenameTabDialog;

class RenameTabDialogPersistentSettings : public DialogSettings
{
public:

	static RenameTabDialogPersistentSettings &GetInstance();

private:

	friend RenameTabDialog;

	static const TCHAR SETTINGS_KEY[];

	RenameTabDialogPersistentSettings();

	RenameTabDialogPersistentSettings(const RenameTabDialogPersistentSettings &);
	RenameTabDialogPersistentSettings & operator=(const RenameTabDialogPersistentSettings &);
};

class RenameTabDialog : public BaseDialog
{
public:

	RenameTabDialog(HINSTANCE hInstance, HWND hParent, int tabId, TabContainer *tabContainer);

protected:

	INT_PTR	OnInitDialog() override;
	INT_PTR	OnCommand(WPARAM wParam,LPARAM lParam) override;
	INT_PTR	OnClose() override;

	void	SaveState() override;

private:

	void	OnUseFolderName();
	void	OnUseCustomName();
	void	OnOk();
	void	OnCancel();

	void	OnTabClosed(int tabId);

	RenameTabDialogPersistentSettings	*m_prtdps;

	TabContainer	*m_tabContainer;
	int		m_tabId;

	std::vector<boost::signals2::scoped_connection>	m_connections;
};