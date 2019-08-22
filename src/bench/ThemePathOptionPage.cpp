#include "ThemePathOptionPage.h"
#include "ui_ThemePathOptionPage.h"
#include <QFileDialog>
#include <QSettings>

ThemePathOptionPage::ThemePathOptionPage(QWidget *parent) :
                                                            QWidget(parent),
                                                            ui(new Ui::ThemePathOptionPage)
{
    ui->setupUi(this);
}

ThemePathOptionPage::~ThemePathOptionPage() { delete ui; }

void ThemePathOptionPage::apply() {
    QSettings s;
    s.setValue("qmlsyle", ui->txtPath->text());
    s.sync();
}

void ThemePathOptionPage::on_btnClear_clicked() { ui->txtPath->setText(""); }

void ThemePathOptionPage::on_btnBrowse_clicked() {
    QString path = QFileDialog::getExistingDirectory(this, "Add Import Path");
    if (path.isEmpty()) {
        return;
    }
    ui->txtPath->setText(path);
}
