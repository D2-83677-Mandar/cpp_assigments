cout << "How many accounts you want to create? ";
            cin >> size;
            ptr = new account();
            ptr->acceptData();
            accList.push_back(ptr);

            break;
        case 2:
            for (int i = 0; i < accList.size(); i++)
            {

                cout << "inside for" << endl;
                accList[i]->displaydata();