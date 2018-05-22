/* Copyright 2015-2018 MultiMC Contributors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "WorldListPage.h"
#include "ui_WorldListPage.h"
#include <QEvent>
#include <QKeyEvent>
#include <QClipboard>
#include <QMessageBox>
#include <QTreeView>
#include <QInputDialog>
#include <QDebug>

WorldListPage::WorldListPage
(
	QString id,
	QString iconName,
	QString displayName, QString helpPage,
	QWidget *parent
)
: QWidget(parent), ui(new Ui::WorldListPage), m_iconName(iconName), m_id(id), m_displayName(displayName), m_helpName(helpPage)
{
	ui->setupUi(this);
	ui->worldTreeView->setSortingEnabled(true);
	ui->worldTreeView->installEventFilter(this);
}

void WorldListPage::openedImpl()
{
}

void WorldListPage::closedImpl()
{
}

WorldListPage::~WorldListPage()
{
	delete ui;
}

bool WorldListPage::shouldDisplay() const
{
	return true;
}
