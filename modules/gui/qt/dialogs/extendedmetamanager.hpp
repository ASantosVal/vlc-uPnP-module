/*****************************************************************************
 * extendedmetamanager.hpp : Extended Metadata Manager dialogs
 ****************************************************************************
 * Copyright (C) 2017 Asier Santos Valcárcel
 * Authors: Asier Santos Valcárcel
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 *****************************************************************************/

#ifndef QVLC_EXTMETAMANAGER_DIALOG_H_
#define QVLC_EXTMETAMANAGER_DIALOG_H_ 1

//aliases for the table's columns' name
#define COL_CHECKBOX 0
#define COL_TITLE 1
#define COL_ARTIST 2
#define COL_ALBUM 3
#define COL_GENRE 4
#define COL_TRACKNUM 5
#define COL_PUBLISHER 6
#define COL_COPYRIGHT 7
#define COL_ARTWORK 8

#include "util/qvlcframe.hpp"
#include "util/singleton.hpp"

#include "ui/extmetamanager.h" // Include de compiled version of extmetamanager.ui

class ExtMetaManagerDialog : public QVLCDialog, public Singleton<ExtMetaManagerDialog>
{
    Q_OBJECT
private:
    ExtMetaManagerDialog( intf_thread_t * );
    virtual ~ExtMetaManagerDialog();

    const char *help_text = "Lorem ipsum dolor sit amet, consectetur adipiscing "
    "elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. U t"
    "enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut "
    "aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in "
    "voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint "
    "occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit "
    "anim id est laborum."; //TODO: Write a proper text here
    const char *about_text = help_text; //TODO: Write a proper text here

    Ui::ExtMetaManagerWidget ui; //add de ui
private slots:
    void close() Q_DECL_OVERRIDE;

    void getFromPlaylist();
    void getFromFolder();
    void searchNow();
    void saveAll();
    void restoreAll();
    void help();
    void about();
    void showArtwork();
    void clearTable();
    void addTableEntry(QString url);
    void updateArtwork(int row, int column);
    void showArtwork();
    // QStringList getItemFromRow(int row);
    // input_item_t getItemFromURI(int row);

    friend class    Singleton<ExtMetaManagerDialog>;
public:
    void toggleVisible();
};

#endif
