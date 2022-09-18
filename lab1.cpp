#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

struct List {
  List *next;
  List *prev;
  char name[20];
  double avg_mark;
} *head = nullptr, *tail = nullptr;

void add(char name[], double avg_mark) {
  if (head == nullptr) {
    head = new List;

    head->next = nullptr;
    head->prev = nullptr;

    strcpy(head->name, name);
    head->avg_mark = avg_mark;

    tail = head;
  } else {
    tail->next = new List;

    tail->next->prev = tail;
    tail = tail->next;
    tail->next = nullptr;

    strcpy(tail->name, name);
    tail->avg_mark = avg_mark;
  }
}

void del_first() {
  List *first = head;
  if (head->next != nullptr) {
    head = head->next;
    head->prev = nullptr;
    delete first;
  } else {
    delete head;
    head = nullptr;
  }
}

void del_last() {
  List *last = tail;
  if (tail->prev != nullptr) {
    tail = tail->prev;
    tail->next = nullptr;
    delete last;
  } else {
    delete head;
    head = nullptr;
  }
}

void print_list() {
  List *current = head;

  int counter = 1;
  while (current) {
    cout << "#" << counter++ << "\nName: " << current->name
         << "\nAverage mark: " << current->avg_mark << "\n\n";
    current = current->next;
  }
}

void print_list_backwards() {
  List *current = tail;

  int counter = 1;
  while (current) {
    cout << "#" << counter++ << "\nName: " << current->name
         << "\nAverage mark: " << current->avg_mark << "\n\n";
    current = current->prev;
  }
}

void serialize() {
  ofstream ofs("file.bin", ios::binary);
  List *current = head;
  while (current) {
    ofs.write(current->name, sizeof(current->name));
    ofs.write((char *)&current->avg_mark, sizeof(current->avg_mark));
    current = current->next;
  }
  ofs.close();
}

void deserialize() {
  ifstream ifs("file.bin", ios::binary);
  if (!ifs) return;
  char name[20];
  double avg_mark;
  while (true) {
    ifs.read(name, sizeof(name));
    ifs.read((char *)&avg_mark, sizeof(avg_mark));
    if (ifs.eof()) {
      break;
    }
    add(name, avg_mark);
  }
  ifs.close();
}

int main() {
  int temp;
  /*
  add("Erika", 4.432);
  add("Kesha", 3.892);
  add("Viktoria", 4.021);
  add("Nikodim", 4.213);
  add("Vitaliy", 3.321);
  */
  
  //serialize();
  // deserialize();

  while (true) {
    system("clear");

    cout << "MENU:\n";
    cout << "#1 Add\n";
    cout << "#2 Delete first\n";
    cout << "#3 Delete last\n";
    cout << "#4 Print\n";
    cout << "#5 Print backwards\n";
    cout << "#6 Serialize\n";
    cout << "#7 Deserialize\n";
    cout << "#0 Exit\n";
    cout << "\nOption: ";

    bool exitflag = false;

    int option;
    cin >> option;

    switch (option) {
    case 1:
      char name[20];
      cout << "\nName: ";
      cin >> name;

      double avg_mark;
      cout << "\nAverage mark: ";
      cin >> avg_mark;

      add(name, avg_mark);
      break;

    case 2:
      del_first();
      break;

    case 3:
      del_last();
      break;

    case 4:
      cout << "\nLIST:\n";
      print_list();
      cin >> temp;
      break;

    case 5:
      cout << "\nLIST:\n";
      print_list_backwards();
      cin >> temp;
      break;

    case 6:
      serialize();
      break;

    case 7:
      deserialize();
      break;

    case 0:
      exitflag = true;
      break;
    }

    if (exitflag)
      break;
  }
}
