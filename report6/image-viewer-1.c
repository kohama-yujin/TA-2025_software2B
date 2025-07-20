// ソース 2-1
// 何もないウィンドウを表示するGTKアプリケーション
#include <gtk/gtk.h>

// コールバック関数の宣言
static void
on_activate (GApplication *app, gpointer* user_data){
    // windowウィジェット作成
    // appはGTK_APPLICATIONにキャスト
    GtkWidget *window = gtk_application_window_new (GTK_APPLICATION (app));
    // タイトルセット
    // windowはGTK_WINDOWにキャスト
    gtk_window_set_title(GTK_WINDOW(window), "Image Viewer");
    // デフォルトサイズセット
    // windowはGTK_WINDOWにキャスト
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    // windowウィジェットを表示
    gtk_window_present(GTK_WINDOW(window));
}

int main (int argc, char *argv[]){
    // GTKアプリケーションを作成
    // アプリケーションIDは"org.gtk.tutorial"
    // G_APPLICATION_FLAGS_NONEはフラグなし
    GtkApplication *app = gtk_application_new ("org.gtk.tutorial", G_APPLICATION_FLAGS_NONE);
    // activateシグナルにon_activateコールバック関数を接続
    // 開始（ウィンドウ表示など）イベント発生時、activateシグナルが発生し、on_activateコールバック関数が呼び出される
    // appはG_OBJECTにキャスト
    g_signal_connect (G_OBJECT (app), "activate", G_CALLBACK (on_activate), NULL);
    // アプリケーションを実行
    // メインループを開始
    g_application_run (G_APPLICATION (app), argc, argv);

    return 0;
}