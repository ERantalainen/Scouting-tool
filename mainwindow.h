#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CreateTeam_clicked();

    void on_EditTeam_clicked();

    void on_ViewStats_clicked();

    void on_BackMap_clicked();

    void on_BackStats_clicked();

    void on_BackEdit_clicked();

    void on_BackCreate_clicked();

    void on_BackDel_clicked();

    void on_ViewMap_clicked();

    void on_saveteam_clicked();

    void on_Pages_currentChanged(int arg1);

    void on_TeamSelectStats_currentIndexChanged(int index);

    void on_StatsMap_currentIndexChanged(int index);

    void on_EditTeamSel_currentIndexChanged(int index);

    void on_EditCompSel_currentIndexChanged(int index);

    void on_EditTankSel_currentIndexChanged(int index);

    void EditComp();

    void on_EditDps1Sel_currentIndexChanged(int index);

    void on_EditDps2Sel_currentIndexChanged(int index);

    void on_EditSupp1Sel_currentIndexChanged(int index);

    void on_EditSupp2Sel_currentIndexChanged(int index);

    void on_EditCompSel_activated(int index);

    void on_AddCompMenu_clicked();

    void on_AddComp_clicked();

    void on_EditMapSel_currentIndexChanged(int index);

    void on_DeleteTeam_clicked();

    void on_DelButton_clicked();

    void on_DelConfirm_accepted();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
