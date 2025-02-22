#pragma once

#include <QDebug>
#include <QDialog>
#include <QFileDialog>
#include <QDialogButtonBox>
#include <QMessageBox>
#include <QtGui>
// #include "MainWindow.h"
#include "ui_PreferencesDialog.h"

namespace Fragmentarium
{
namespace GUI
{

class PreferencesDialog : public QDialog
{
    Q_OBJECT
public:
    PreferencesDialog ( QWidget * )
    {
        setObjectName("PreferencesDialog");
        m_ui.setupUi(this);
        readSettings();
        connect(m_ui.logFilePathToolButton, SIGNAL(released()), this, SLOT(getLogFilename()));
        connect(m_ui.includePathsToolButton, SIGNAL(released()), this, SLOT(getIncludePaths()));
        connect(m_ui.exrBinPathsToolButton, SIGNAL(released()), this, SLOT(getExrBinPaths()));
        connect(m_ui.guiStylesheetToolButton, SIGNAL(released()), this, SLOT(getGuiStylesheet()));
    };
    ~PreferencesDialog() {};

public slots:

    void getLogFilename() {
        QString fileName;
        QString filter = tr("Log File (*.log);;All Files (*.*)");
        QFileDialog dialog(this, QString("Select a file."), QString(),filter);
        dialog.setFileMode(QFileDialog::AnyFile);
        if (dialog.exec())
            fileName = dialog.selectedFiles().first();
        if (!fileName.isEmpty()) {
            m_ui.logFilePathLineEdit->setText(fileName);
        }
    }

    void getIncludePaths() {
        QStringList pathNames;
        QFileDialog dialog(this, QString("Select a path."));
        dialog.setFileMode(QFileDialog::Directory);
        dialog.setOption(QFileDialog::ShowDirsOnly, true);
        if (dialog.exec())
            pathNames = dialog.selectedFiles();
        if (!pathNames.isEmpty()) {
            m_ui.includePathsLineEdit->setText(pathNames.join(";"));
        }
    }

    void getExrBinPaths() {
        QStringList pathNames;
        QFileDialog dialog(this, QString("Select a path."));
        dialog.setFileMode(QFileDialog::Directory);
        dialog.setOption(QFileDialog::ShowDirsOnly, true);
        if (dialog.exec())
            pathNames = dialog.selectedFiles();
        if (!pathNames.isEmpty()) {
            m_ui.exrBinPathsLineEdit->setText(pathNames.join(";"));
        }
    }

    void getSupportProgramPaths() {
        QStringList pathNames;
        QFileDialog dialog(this, QString("Select a path."));
        dialog.setFileMode(QFileDialog::Directory);
        dialog.setOption(QFileDialog::ShowDirsOnly, true);
        if (dialog.exec())
            pathNames = dialog.selectedFiles();
        if (!pathNames.isEmpty()) {
            m_ui.supportProgramBinPathsLineEdit->setText(pathNames.join(";"));
        }
    }

    void getEditorStylesheet() {
        QString fileName;
        QString filter = tr("Stylesheet (*.qss);;All Files (*.*)");
        QFileDialog dialog(this, QString("Select a file."), QString(),filter);
        dialog.setFileMode(QFileDialog::ExistingFile);
        if (dialog.exec())
            fileName = dialog.selectedFiles().first();
        if (!fileName.isEmpty()) {
            m_ui.editorStylesheetLineEdit->setText(fileName);
        }
    }

    void getGuiStylesheet() {
        QString fileName;
        QString filter = tr("Stylesheet (*.qss);;All Files (*.*)");
        QFileDialog dialog(this, QString("Select a file."), QString("./Misc/qss"),filter);
        dialog.setFileMode(QFileDialog::ExistingFile);
        if (dialog.exec())
            fileName = dialog.selectedFiles().first();
        if (!fileName.isEmpty()) {
            m_ui.guiStylesheetLineEdit->setText(fileName);
        }
    }


private slots:

    void accept()
    {
        saveSettings();
        QDialog::accept();
    }

    void readSettings()
    {
        QSettings settings;
        m_ui.logToFileCheckBox->setChecked (settings.value ( "logToFile", true ).toBool() );
        m_ui.logFilePathLineEdit->setText (settings.value ( "logFilePath", "fragm.log" ).toString() );
        m_ui.maxLogFileSizeSpinBox->setValue (settings.value ( "maxLogFileSize", 125 ).toInt() );
        m_ui.moveMainCheckBox->setChecked (settings.value ( "moveMain", true ).toBool() );
        m_ui.lineNumbersCheckBox->setChecked (settings.value ( "lineNumbers", true ).toBool() );
        m_ui.loopPlayCheckBox->setChecked (settings.value ( "loopPlay", false ).toBool() );
        m_ui.drawGLPathsCheckBox->setChecked (settings.value ( "drawGLPaths", true ).toBool() );
        m_ui.splineOccCheckBox->setChecked (settings.value ( "splineOcc", true ).toBool() );
        m_ui.autoRunCheckBox->setChecked(settings.value("autorun", true).toBool());
        m_ui.autoLoadCheckBox->setChecked (settings.value ( "autoload", false ).toBool() );
        m_ui.saveEasingCheckBox->setChecked (settings.value ( "saveEasing", true ).toBool() );
        m_ui.useDefinesCheckBox->setChecked (settings.value ( "useDefines", false ).toBool() );
        m_ui.refreshRateSpinBox->setValue (settings.value ( "refreshRate", 20 ).toInt() );
        m_ui.fpsSpinBox->setValue(settings.value("fps", 25).toInt());
        m_ui.maxRecentFilesSpinBox->setValue (settings.value ( "maxRecentFiles", 5 ).toInt() );
        m_ui.includePathsLineEdit->setText (settings.value ( "includePaths", "Examples/Include;" ).toString() );
        m_ui.fullPathInRecentFilesListCheckBox->setChecked (settings.value ( "fullPathInRecentFilesList", false ).toBool() );
        m_ui.includeWithAutoSaveCheckBox->setChecked (settings.value ( "includeWithAutoSave", true ).toBool() );
        m_ui.jtloeCheckBox->setChecked (settings.value ( "jumpToLineOnError", true ).toBool() );
        m_ui.ddCameraModeCheckBox->setChecked (settings.value ( "ddCameraMode", false ).toBool() );
        m_ui.playRestartModeCheckBox->setChecked (settings.value ( "playRestartMode", false ).toBool() );
        m_ui.enableGLDebugCheckBox->setChecked (settings.value ( "enableGLDebug", false ).toBool() );
        m_ui.compatPatchCheckBox->setChecked (settings.value ( "compatPatch", true ).toBool() );
#ifdef USE_OPEN_EXR
        m_ui.exrBinPathsLineEdit->setText (settings.value ( "exrBinPaths", "./bin;/usr/bin;" ).toString() );
#endif // USE_OPEN_EXR
        m_ui.supportProgramBinPathsLineEdit->setText (settings.value ( "supportProgramBinPaths", "./bin" ).toString() );
        m_ui.editorStylesheetLineEdit->setText (settings.value ( "editorStylesheet", "font: 9pt Courier;" ).toString() );
        m_ui.useMimetypesCheckBox->setChecked (settings.value ( "useMimetypes", false ).toBool() );
        m_ui.logLinesSpinBox->setValue (settings.value ( "maxLogLines", 10 ).toInt() );
        m_ui.editorThemeComboBox->setCurrentIndex( settings.value ( "editorTheme", 0 ).toInt() );
        m_ui.guiStylesheetLineEdit->setText (settings.value ( "guiStylesheet", "" ).toString() );
    }

    void saveSettings()
    {
        QSettings settings;
        settings.setValue("logToFile", m_ui.logToFileCheckBox->isChecked());
        settings.setValue("logFilePath", m_ui.logFilePathLineEdit->text());
        settings.setValue("maxLogFileSize", m_ui.maxLogFileSizeSpinBox->value());
        settings.setValue("moveMain", m_ui.moveMainCheckBox->isChecked());
        settings.setValue("lineNumbers", m_ui.lineNumbersCheckBox->isChecked());
        settings.setValue("loopPlay", m_ui.loopPlayCheckBox->isChecked());
        settings.setValue("drawGLPaths", m_ui.drawGLPathsCheckBox->isChecked());
        settings.setValue("splineOcc", m_ui.splineOccCheckBox->isChecked());
        settings.setValue("autorun", m_ui.autoRunCheckBox->isChecked());
        settings.setValue("autoload", m_ui.autoLoadCheckBox->isChecked());
        settings.setValue("saveEasing", m_ui.saveEasingCheckBox->isChecked());
        settings.setValue("useDefines", m_ui.useDefinesCheckBox->isChecked());
        settings.setValue("refreshRate",  m_ui.refreshRateSpinBox->value());
        settings.setValue("fps", m_ui.fpsSpinBox->value());
        settings.setValue("maxRecentFiles", m_ui.maxRecentFilesSpinBox->value());
        settings.setValue("includePaths", m_ui.includePathsLineEdit->text());
        settings.setValue("fullPathInRecentFilesList", m_ui.fullPathInRecentFilesListCheckBox->isChecked() );
        settings.setValue("includeWithAutoSave", m_ui.includeWithAutoSaveCheckBox->isChecked() );
        settings.setValue("jumpToLineOnError", m_ui.jtloeCheckBox->isChecked() );
        settings.setValue("ddCameraMode", m_ui.ddCameraModeCheckBox->isChecked() );
        settings.setValue("playRestartMode", m_ui.playRestartModeCheckBox->isChecked() );
        settings.setValue("enableGLDebug", m_ui.enableGLDebugCheckBox->isChecked() );
        settings.setValue("compatPatch", m_ui.compatPatchCheckBox->isChecked() );
#ifdef USE_OPEN_EXR
        settings.setValue("exrBinPaths", m_ui.exrBinPathsLineEdit->text());
#endif // USE_OPEN_EXR
        settings.setValue("supportProgramBinPaths", m_ui.supportProgramBinPathsLineEdit->text());
        settings.setValue("editorStylesheet", m_ui.editorStylesheetLineEdit->text());
        settings.setValue("useMimetypes", m_ui.useMimetypesCheckBox->isChecked() );
        settings.setValue("maxLogLines", m_ui.logLinesSpinBox->value());
        settings.setValue("editorTheme",  m_ui.editorThemeComboBox->currentIndex());
        settings.setValue("guiStylesheet", m_ui.guiStylesheetLineEdit->text());
        settings.sync();
    }

private:
    Ui::PreferencesDialog m_ui;
};
} // namespace GUI
} // namespace Fragmentarium
