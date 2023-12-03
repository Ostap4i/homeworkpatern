#include <iostream>
#include <vector>
#include <string>

//class TextEditor {
//public:
    //virtual void display() const = 0;
    //virtual ~TextEditor() = default;
//};

// Реалізація базового класу текстового редактора

//class BasicTextEditor : public TextEditor {
//public:
    //void display() const override {
        //std::cout << "Basic Text Editor\n";
    //}
//};

// Базовий клас для плагінів (декораторів)

//class EditorDecorator : public TextEditor {
//protected:
    //std::unique_ptr<TextEditor> editor;

//public:
    //EditorDecorator(std::unique_ptr<TextEditor> e) : editor(std::move(e)) {}

    //void display() const override {
       // if (editor) {
         //   editor->display();
        //}
    //}
//};

// Плагін для підсвічування тексту

//class SyntaxHighlightPlugin : public EditorDecorator {
//public:
    //SyntaxHighlightPlugin(std::unique_ptr<TextEditor> e) : EditorDecorator(std::move(e)) {}

    //void display() const override {
      //  if (editor) {
        //    editor->display();
          //  std::cout << " + Syntax Highlighting\n";
        //}
    //}
//};

// Плагін для автодоповнення коду

//class AutocompletePlugin : public EditorDecorator {
//public:
  //  AutocompletePlugin(std::unique_ptr<TextEditor> e) : EditorDecorator(std::move(e)) {}

//    void display() const override {
//        if (editor) {
   //         editor->display();
     //       std::cout << " + Autocomplete\n";
      //  }
    //}
//};

//int main() {
    // Створення базового текстового редактора

    //std::unique_ptr<TextEditor> editor = std::make_unique<BasicTextEditor>();

    // Додавання плагінів
    //editor = std::make_unique<SyntaxHighlightPlugin>(std::move(editor));
    //editor = std::make_unique<AutocompletePlugin>(std::move(editor));

    // Виведення функціональності редактора з усіма плагінами

    //editor->display();

    //return 0;
//}



//Task 2

//class TV {
//public:
  //  void turnOn() {
    //    std::cout << "TV Turn on\n";
    //}

    //void turnOff() {
      //  std::cout << "TV Turn of\n";
    //}
//};


//class Conditioner {
//public:
  //  void turnOn() {
    //    std::cout << "Conditioner Turn on \n";
    //}

    //void turnOff() {
      //  std::cout << "Conditioner Turn of\n";
    //}
//};


//class Lights {
//public:
  //  void turnOn() {
    //    std::cout << "lights Turn on \n";
    //}

    //void turnOff() {
      //  std::cout << "lights Turn of\n";
    //}
//};


//class HomeFacade {
//private:
  //  TV tv;
    //Conditioner ac;
   // Lights lights;

//public:
  //  void turnOnAllDevices() {
    //    tv.turnOn();
      //  ac.turnOn();
        //lights.turnOn();
    //}

    //void turnOffAllDevices() {
      //  tv.turnOff();
        //ac.turnOff();
        //lights.turnOff();
   // }
//};

//int main() {
  
  //  HomeFacade homeFacade;

   
    //homeFacade.turnOnAllDevices();

    //std::cout << "-----\n";

    //homeFacade.turnOffAllDevices();

    //return 0;
//}


//Task 3

class StorageDevice {
public:
    virtual void storeData(const std::string& data) = 0;
    virtual std::string retrieveData() const = 0;
    virtual ~StorageDevice() = default;
};

class USBFlashDrive : public StorageDevice {
private:
    std::string storedData;

public:
    void storeData(const std::string& data) override {
        storedData = data;
        std::cout << "Data stored on USB Flash Drive.\n";
    }

    std::string retrieveData() const override {
        std::cout << "Data retrieved from USB Flash Drive.\n";
        return storedData;
    }
};

class HardDisk : public StorageDevice {
private:
    std::string storedData;

public:
    void storeData(const std::string& data) override {
        storedData = data;
        std::cout << "Data stored on Hard Disk.\n";
    }

    std::string retrieveData() const override {
        std::cout << "Data retrieved from Hard Disk.\n";
        return storedData;
    }
};


class DataManager {
private:
    StorageDevice* storageDevice;

public:
    DataManager(StorageDevice* device) : storageDevice(device) {}

    void storeData(const std::string& data) {
        storageDevice->storeData(data);
    }

    std::string retrieveData() const {
        return storageDevice->retrieveData();
    }
};

int main() {
    USBFlashDrive usbFlashDrive;
    HardDisk hardDisk;

    DataManager usbDataManager(&usbFlashDrive);
    usbDataManager.storeData("Hello from USB!");

    DataManager hardDiskDataManager(&hardDisk);
    hardDiskDataManager.storeData("Hello from Hard Disk!");

    std::cout << "Retrieving data:\n";
    std::cout << "USB Data: " << usbDataManager.retrieveData() << "\n";
    std::cout << "Hard Disk Data: " << hardDiskDataManager.retrieveData() << "\n";

    return 0;
}