#include "FS.h"
#include "SPIFFS.h"

/* You only need to format SPIFFS the first time you run a
   test or else use the SPIFFS plugin to create a partition
   https://github.com/me-no-dev/arduino-esp32fs-plugin */
#define FORMAT_SPIFFS_IF_FAILED true

typedef struct 
{
  char ssid[25];
  char pass[25];
  char url[50];
}config;

config siwi_config;
config read_config;

void readFile(fs::FS &fs, const char * path){

  memset(&read_config, 0, sizeof(read_config));
  Serial.printf("Reading file: %s\r\n", path);

  File file = fs.open(path);
  if(!file || file.isDirectory()){
      Serial.println("- failed to open file for reading");
      return;
  }

  Serial.println("- read from file:");
  // while(file.available()){

    //     //Serial.write(file.read());
    // }
  file.readBytes((char*)&read_config, sizeof(read_config));
  file.close();

  Serial.print("SSID:"), 
  Serial.println(read_config.ssid);
  Serial.print("PASS:"); 
  Serial.println(read_config.pass);

}

void writeFile(fs::FS &fs, const char * path, const char * message){
    Serial.printf("Writing file: %s\r\n", path);

    File file = fs.open(path, FILE_WRITE);
    if(!file){
        Serial.println("- failed to open file for writing");
        return;
    }
    if(file.write((uint8_t*)message, sizeof(siwi_config))){
        Serial.println("- file written");
    } else {
        Serial.println("- write failed");
    }
    file.close();
}

void renameFile(fs::FS &fs, const char * path1, const char * path2){
    Serial.printf("Renaming file %s to %s\r\n", path1, path2);
    if (fs.rename(path1, path2)) {
        Serial.println("- file renamed");
    } else {
        Serial.println("- rename failed");
    }
}

void deleteFile(fs::FS &fs, const char * path){
    Serial.printf("Deleting file: %s\r\n", path);
    if(fs.remove(path)){
        Serial.println("- file deleted");
    } else {
        Serial.println("- delete failed");
    }
}

void setup(){
    Serial.begin(115200);
    if(!SPIFFS.begin(FORMAT_SPIFFS_IF_FAILED)){
        Serial.println("SPIFFS Mount Failed");
        return;
    }

    //config *siwi_config;

    memset(siwi_config.ssid, 0, sizeof(siwi_config.ssid));
    strcpy(siwi_config.ssid, "siwi");

    memset(siwi_config.pass, 0, sizeof(siwi_config.pass));
    strcpy(siwi_config.pass, "siwi1234");
    
    //listDir(SPIFFS, "/", 0);
    writeFile(SPIFFS, "/config_file.txt", (char*)&siwi_config);
    delay(100);
    readFile(SPIFFS, "/config_file.txt");

    deleteFile(SPIFFS, "/config_file.txt");
}

void loop(){

}
