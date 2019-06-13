#pragma once
#ifndef PLUGINWIDGET_H
#define PLUGINWIDGET_H

#include "PreferencesWidget.h"
#include <QtGui/QStandardItemModel>

#include "ui_PPluginWidget.h"

class QComboBox;
class Plugin;

class PluginWidget : public PreferencesWidget
{
    Q_OBJECT

public:
    PluginWidget();
    PreferencesWidget::ResultAction saveSettings();

private slots:
    void addPlugin();
    bool bundledInterpReady();
    void AutoFindPy3();
    void SetPy3();
    void enginePy3PathChanged();
    void enable_disable_controls();
    void useBundledPy3Changed(int);
    void removePlugin();
    void removeAllPlugins();
    void pluginSelected(int row, int col);
    void pluginMapChanged(int);

private:
    enum PluginFields {
        NameField        = 0,
        VersionField     = 1,
        AuthorField      = 2,
        TypeField        = 3,
        EngineField      = 4,
        OSListField      = 5
    };

    void readSettings();
    void connectSignalsToSlots();
    void setPluginTableRow(Plugin *p, int row);

    Ui::PluginWidget ui;
    bool m_isDirty;
    QString m_LastFolderOpen;
    bool m_useBundledInterp;
    QList<QComboBox*> m_qlcbxs;
};

#endif // PLUGINWIDGET_H
