#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) //OPCJA 1
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

static int writer(char *data, size_t size, size_t nmemb, std::string *buffer) {     //OPCJA 2
  int result = 0;
  if (buffer != NULL) {
    buffer->append(data, size * nmemb);
    result = size * nmemb;
  }
  return result;
}

void MainWindow::on_activationButton_clicked()
{
    CURL *curl;
    CURLcode response;
    std::string resString;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    curl = curl_easy_init();
    if(curl) {
      curl_easy_setopt(curl, CURLOPT_URL, "http://slawbit.pl/api-currencyexchange/rates");
      curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writer);
      curl_easy_setopt(curl, CURLOPT_WRITEDATA, &resString);

      response = curl_easy_perform(curl);

      QString responseString = QString::fromStdString(resString);

      /*const char* json = resString.c_str();
      Document document;
      document.Parse(json);
      assert(document.IsObject());
      assert(document.HasMember("response"));
      assert(document["response"].IsObject());
      assert(document["response"].HasMember("data"));
      assert(document["response"]["data"].IsObject());
      assert(document["response"]["data"].HasMember("0"));
      assert(document["response"]["data"]["0"].IsArray());
      assert(document["response"]["data"]["0"].HasMember("date"));
      assert(document["response"]["data"]["0"]["date"].IsString());
      Value& stringo=document["response"]["data"]["0"]["date"];*/




          /* Check for errors */
      if(response != CURLE_OK)
         ui->textField->setText("curl_easy_perform() failed!");
      else
          ui->textField->setText(responseString);
          //ui->textField->setText(document["response"]["data"]["0"]["date"].GetString());

          /* always cleanup */
      curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

void MainWindow::on_rapidButton_clicked()
{
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;
    d.Parse(json);
    // 2. Modify it by DOM.
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);
    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    ui->textField->setText(buffer.GetString());
}
