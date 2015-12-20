/*
 * c++ primer 4ed, class
 * chapter 13.4: Message, interesting
 */

#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

class Message;
class Folder{
 public:
  Folder() {};
  void addMsg(Message* msg) { msgs.insert(msg); }
  void remMsg(Message* msg) { msgs.erase(msg); }
  void showMsg(ostream &out);
 private:
  set<Message*> msgs;
  
  // no copyable allowed for now
  Folder(const Folder&);
  Folder& operator=(const Folder&);
};

class Message{
 public:
  Message(const string &str=""):contents(str) {}
  Message(const Message&);
  Message& operator=(const Message&);
  ~Message();

  void save(Folder&);
  void remove(Folder&);
  void show(ostream& out) { out << contents << "\n"; }
 private:
  string contents;
  set<Folder*> folders;
  void put_Msg_in_Folders(const set<Folder*>&);
  void remove_Msg_from_Folders();
  void addFldr(Folder*f) { folders.insert(f);}
  void remFldr(Folder* f) { folders.erase(f);}
};

Message::Message(const Message& rhs):
    contents(rhs.contents),folders(rhs.folders){
  put_Msg_in_Folders(folders);
}

Message& Message::operator=(const Message& rhs) {
  if(this != &rhs) {    
    remove_Msg_from_Folders();
    
    contents = rhs.contents;
    folders = rhs.folders;
    put_Msg_in_Folders(folders);
  }
  return *this;
}

Message::~Message() {
  remove_Msg_from_Folders();
}

void Message::put_Msg_in_Folders(const set<Folder*>& folders) {
  set<Folder*>::const_iterator it = folders.begin();
  while(it != folders.end()) {
    (*it)->addMsg(this);
    ++it;
  }
}

void Message::remove_Msg_from_Folders() {
  set<Folder*>::const_iterator it = folders.begin();
  while(it != folders.end()) {
    (*it)->remMsg(this);
    ++it;
  }
}

// doubly
void Message::save(Folder& folder) {
  addFldr(&folder);
  folder.addMsg(this);
}

// doubly
void Message::remove(Folder& folder) {
  remFldr(&folder);
  folder.remMsg(this);
}

// here can see 'show()' in Message have defined 
void Folder::showMsg(ostream &out) {
  set<Message*>::const_iterator it = msgs.begin();
  while(it != msgs.end()) {
    (*it)->show(out);
    ++it;
  }
}

int main() {
  Folder folder1,folder2,folder3,folder4,folder5;
  Message msg1("2015-12-21");
  Message msg2("2015-12-22");
  Message msg3("2015-12-23");
  Message msg4("2015-12-24");
  Message msg5("2015-12-25");
  
  msg1.save(folder1);
  msg2.save(folder2);
  msg3.save(folder3);
  msg4.save(folder4);
  msg5.save(folder5);

  msg2 = msg1;
  msg3 = msg2;
  Message msg6(msg5);

  cout << "--1--" << endl;
  folder1.showMsg(cout);
  cout << "--2--" << endl;
  folder2.showMsg(cout);
  cout << "--3--" << endl;
  folder3.showMsg(cout);
  cout << "--4--" << endl;
  folder4.showMsg(cout);
  cout << "--5--" << endl;
  folder5.showMsg(cout);
  
  return 0;
}
