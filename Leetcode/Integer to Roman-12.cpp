class Solution {
public:
    string intToRoman(int num) {
        string st = "";
        while (num >= 1000) {
            st += 'M';
            num -= 1000;
        }
        //999 
        while (num >= 900) {
            st += "CM";
            num -= 900;
        }
        while (num >= 500) {
            st += 'D';
            num -= 500;
        }
        while (num >= 400) {
            st += "CD";
            num -= 400;
        }
        while (num >= 100) {
            st += 'C';
            num -= 100;
        }
        
        while (num >= 90) {
            st += "XC";
            num -= 90;
        }
        while (num >= 50) {
            st += 'L';
            num -= 50;
        }

        while (num >= 40) {
            st += "XL";
            num -= 40;
        }

        while (num >= 10) {
            st += 'X';
            num -= 10;
        }
        while (num >= 9) {
            st += "IX";
            num -= 9;
        }
         while (num >= 5) {
            st += 'V';
            num -= 5;
        }

        
        while (num >= 4) {
            st += "IV";
            num -= 4;
        }
        while (num >= 1) {
            st += 'I';
            num -= 1;
        }
        return st;
    }
};