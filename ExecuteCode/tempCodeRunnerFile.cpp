char temp=WelcomeScreen::Show();
        if (temp<'1' || temp>'3'){
            cout << "Vui long chon lai!\n";
            system("pause");
            system("cls");
        }
        else{
            if (temp=='1'){
//                GuestLogin();
            cout << "G";
                break;
            }
            else if (temp=='2'){
                cout << "E";
                break;
            }
            else exit(1);
        }