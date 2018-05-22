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

WorldListPage::WorldListPage(QString id,
							 QString iconName, QString displayName, QString helpPage,
							 QWidget *parent)
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

bool WorldListPage::worldListFilter(QKeyEvent *keyEvent)
{
	switch (keyEvent->key())
	{
	case Qt::Key_Delete:
		on_rmWorldBtn_clicked();
		return true;
	default:
		break;
	}
	return QWidget::eventFilter(ui->worldTreeView, keyEvent);
}

bool WorldListPage::eventFilter(QObject *obj, QEvent *ev)
{
	if (ev->type() != QEvent::KeyPress)
	{
		return QWidget::eventFilter(obj, ev);
	}
	QKeyEvent *keyEvent = static_cast<QKeyEvent *>(ev);
	if (obj == ui->worldTreeView)
		return worldListFilter(keyEvent);
	return QWidget::eventFilter(obj, ev);
}

void WorldListPage::on_rmWorldBtn_clicked()
{
	auto proxiedIndex = getSelectedWorld();

	if(!proxiedIndex.isValid())
		return;

	auto result = QMessageBox::question(this,
				tr("Are you sure?"),
				tr("This will remove the selected world permenantly.\n"
					"The world will be gone forever (A LONG TIME).\n"
					"\n"
					"Do you want to continue?"));
	if(result != QMessageBox::Yes)
	{
		return;
	}
}

void WorldListPage::on_viewFolderBtn_clicked()
{
	qDebug() << "Placeholder";
}

QModelIndex WorldListPage::getSelectedWorld()
{
	qDebug() << "Placeholder";
	return QModelIndex();
}

void WorldListPage::on_copySeedBtn_clicked()
{
	qDebug() << "Placeholder";
}

void WorldListPage::on_mcEditBtn_clicked()
{
	qDebug() << "Placeholder";
}

void WorldListPage::mceditError()
{
	QMessageBox::warning(
		this->parentWidget(),
		tr("MCEdit failed to start!"),
		tr("MCEdit failed to start.\nIt may be necessary to reinstall it.")
	);
}

void WorldListPage::on_addBtn_clicked()
{
	qDebug() << "Placeholder";
}

bool WorldListPage::isWorldSafe(QModelIndex)
{
	return true;
}

bool WorldListPage::worldSafetyNagQuestion()
{
	if(!isWorldSafe(getSelectedWorld()))
	{
		auto result = QMessageBox::question(this, tr("Copy World"), tr("Changing a world while Minecraft is running is potentially unsafe.\nDo you wish to proceed?"));
		if(result == QMessageBox::No)
		{
			return false;
		}
	}
	return true;
}


void WorldListPage::on_copyBtn_clicked()
{
	qDebug() << "Placeholder";
}

void WorldListPage::on_renameBtn_clicked()
{
	qDebug() << "Placeholder";
}

void WorldListPage::on_refreshBtn_clicked()
{
	qDebug() << "Placeholder";
}

