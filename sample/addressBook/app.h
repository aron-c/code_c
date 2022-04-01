#include <iostream>
#include <unistd.h>
#include <string>
using namespace std;

void addressMember(struct addressBook *abs);

void showMember(struct addressBook *abs);
int is_Here(struct addressBook *abs, string name);
void deMember(struct addressBook *abs);
void findMember(struct addressBook *abs);
void modMember(struct addressBook *abs);
void clsMember(struct addressBook *abs);
int showMenu();
void backMenu();