int main(){
  if (4 < 3) {
    print("four is greater than three");
  }

  if (4 <= 3) {
    print("four is greater than or equal to three");
  }

  if (4 > 3) {
    print("four is less than three");
  }

  if (4 >= 3) {
    print("four is less than or equal three");
  }

  if (4 != 3) {
    print("four is not equal to three");
  }

  if (4 == 3) {
    print("four equals three");
  }

  if (!false) {
    print("this should be true");
  }

  if (true && false) {
    print("this should not print");
  }

  if (true || false) {
    print("this should print");
  }

  return 0;
}