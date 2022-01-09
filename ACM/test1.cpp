#include <bits/stdc++.h>
using namespace std;

bool comp1(vector<string> a, vector<string> b)
{
    return a[0] < b[0];
}
bool comp2(vector<string> a, vector<string> b)
{
    return a[1] < b[1];
}
class user
{
  private:
    struct block
    {
        string user_name;
        string user_password;
        int user_type; // 1 admin 2 supervisor 3 regular_user
    };
    vector<block> vec;

  public:
    user();
    ~user();
    // use for file io
    // for convenience we use readable code-set
    void read_user_login_info()
    {
        ifstream is("user_list.db");
        block tmp;
        while (is >> tmp.user_name >> tmp.user_password >> tmp.user_type)
        {
            vec.push_back(tmp);
        }
        is.close();
    }
    void write_user_login_info()
    {
        ofstream os("user_list.db", ios::trunc);
        for (auto it : vec)
        {
            os << it.user_name << " " << it.user_password << " " << it.user_type << "\n";
        }
        os.close();
    }
    pair<int, string> login()
    {
        // log in to the system
        // return user_type and username
        string in_name, in_pwd;
        cout << "Please input username\n";
        cin >> in_name;
        cout << "Please input passowrd\n";
        cin >> in_pwd;
        for (auto it : vec)
        {
            if (in_name == it.user_name)
            {
                if (in_pwd == it.user_password)
                {
                    cout << "Welcome!" << in_name << "\n";
                    return {it.user_type, it.user_name};
                }
                else
                {
                    cout << "Wrong certification, Please retry\n";
                    return {0, ""};
                }
            }
        }
        cout << "Wrong certification, Please retry\n";
        return {0, ""};
    }
    string add_new_admin(string user_nm)
    {
        // only for test
        string user_pw = "123456";
        vec.push_back({user_nm, user_pw, 1});
        return user_pw;
    }
    string add_new_sup(string user_nm)
    {
        // only for test
        string user_pw = "123456";
        vec.push_back({user_nm, user_pw, 2});
        return user_pw;
    }
    string add_new_vol(string user_nm)
    {
        // add new volunteer
        // return the password
        srand(time(0));
        string user_pw = to_string(rand()) + to_string(rand());
        vec.push_back({user_nm, user_pw, 3});
        return user_pw;
    }
};
user::user(){};
user::~user(){};
user gb_user; // Globally store the user info

class volunteer
{
  private:
    vector<string> vol_meta;
    vector<vector<string>> vol_data;

  public:
    volunteer();
    ~volunteer();
    // file io begin//
    void read_vol_info()
    {
        ifstream is1("vol_meta.db");
        string tmp;
        while (is1 >> tmp)
        {
            vol_meta.push_back(tmp);
        }
        is1.close();

        ifstream is2("vol_list.db");
        vector<string> tmpp;
        while (true)
        {
            tmpp.clear();
            for (int i = 0; i < vol_meta.size(); i++)
            {
                if (is2 >> tmp)
                {
                    tmpp.push_back(tmp);
                }
                else
                {
                    goto readend;
                }
            }
            vol_data.push_back(tmpp);
        }
    readend:
        is2.close();
    }
    void write_vol_info()
    {
        ofstream os1("vol_meta.db", ios::trunc);
        for (auto it : vol_meta)
        {
            os1 << it << "\n";
        }
        os1.close();

        ofstream os2("vol_list.db", ios::trunc);
        for (auto it : vol_data)
        {
            for (int i = 0; i < vol_meta.size(); i++)
            {
                if (i < it.size())
                {
                    os2 << it[i] << " ";
                }
                else
                {
                    os2 << "null ";
                }
            }
            os2 << "\n";
        }
        os2.close();
    }
    // file io end//

    vector<string> get_vol_meta()
    {
        return vol_meta;
    }
    vector<pair<string, string>> get_vol_info(string ser_num)
    {
        // for personal user to get his own info
        vector<pair<string, string>> vol_view;
        for (auto it : vol_meta)
        {
            vol_view.push_back(make_pair(it, "null"));
        }
        for (auto it : vol_data)
        {
            if (*it.begin() == ser_num)
            {
                int i = 0;
                for (auto it2 : it)
                {
                    vol_view[i++].second = it2;
                }
                return vol_view;
                break;
            }
        }
        return vol_view;
    }
    void add_new_vol(vector<string> new_piece)
    {
        // add_new_volunteer
        vol_data.push_back(new_piece);
    }
    void add_new_cons(string new_cons)
    {
        // add_new_constraint
        vol_meta.push_back(new_cons);
    }
    void list_all_vol()
    {
        cout << "Please input the sort key?\n1. By No\n2. By Name\n0. No sort\n";
        int sot;
        cin >> sot;
        for (auto it : vol_meta)
        {
            cout << it << "    ";
        }
        cout << "\n";
        vector<vector<string>> tmp = vol_data;
        if (sot == 1)
        {
            sort(tmp.begin(), tmp.end(), comp1);
        }
        else if (sot == 2)
        {
            sort(tmp.begin(), tmp.end(), comp2);
        }

        for (auto it : tmp)
        {
            for (auto iter : it)
            {
                cout << iter << " ";
            }
            cout << "\n";
        }
    }
    void filter_vol(int opr, string tag)
    {
        cout << "Please input the sort key?\n1. By No\n2. By Name\n0. No sort\n";
        int sot;
        cin >> sot;
        for (auto it : vol_meta)
        {
            cout << it << "    ";
        }
        cout << "\n";
        vector<vector<string>> tmp;
        for (auto it : vol_data)
        {
            if (it.size() > opr && it[opr] == tag)
            {
                tmp.push_back(it);
            }
        }
        if (sot == 1)
        {
            sort(tmp.begin(), tmp.end(), comp1);
        }
        else if (sot == 2)
        {
            sort(tmp.begin(), tmp.end(), comp2);
        }

        for (auto it : vol_data)
        {
            if (it.size() > opr && it[opr] == tag)
            {
                for (auto iter : it)
                {
                    cout << iter << " ";
                }
                cout << "\n";
            }
        }
    }
    void modify_attr(string user_nm, int opr, string newval)
    {
        for (auto it : vol_data)
        {
            if (it[0] == user_nm)
            {
                it[opr] = newval;
            }
        }
    }
};
volunteer::volunteer(){};
volunteer::~volunteer(){};
volunteer gb_vol; // Globally store the volunteer info

class job
{
  private:
    struct block
    {
        string title;
        string desc;
    };
    vector<block> vec;

  public:
    job();
    ~job();
    void read_job_info()
    {
        ifstream is("job_list.db");
        block tmp;
        while (is >> tmp.title >> tmp.desc)
        {
            vec.push_back(tmp);
        }
        is.close();
    }
    void write_job_info()
    {
        ofstream os("job_list.db", ios::trunc);
        for (auto it : vec)
        {
            os << it.title << " " << it.desc << "\n";
        }
        os.close();
    }
    void add_job(string in_title, string in_desc)
    {
        vec.push_back({in_title, in_desc});
    }
    int_fast32_t count_job()
    {
        return vec.size();
    }
    void list_job()
    {
        cout << "Job title      Job description\n";
        int cnt = 1;
        for (auto it : vec)
        {
            cout << cnt++ << " " << it.title << " " << it.desc << "\n";
        }
    }
};
job::job(){};
job::~job(){};
job gb_job; //ȫ�ָ�λ����

class admin
{
  private:
  public:
    admin();
    ~admin();
    int display_func()
    {
        cout << "0. Exit system\n";
        cout << "1. Add new constraint\n";
        cout << "2. Display volunteer info\n";
        cout << "3. Search volunteer info\n";
        int opr;
        cin >> opr;
        return opr;
    }
    void add_constraint()
    {
        cout << "Now adding new constraint...\n";
        string in_cons;
        cin >> in_cons;
        gb_vol.add_new_cons(in_cons);
        cout << "New constraint" << in_cons << "has been added\n";
    }
    void list_all_vol()
    {
        gb_vol.list_all_vol();
    }
    void filter_vol()
    {
        cout << "Please input the key you want to filter by\n";
        vector<string> meta_data = gb_vol.get_vol_meta();
        for (int i = 0; i < meta_data.size(); i++)
        {
            cout << i + 1 << "." << meta_data[i] << "\n";
        }
        int opr;
        cin >> opr;
        cout << "Please input the <key,value>\n";
        string tag;
        cin >> tag;
        gb_vol.filter_vol(opr - 1, tag);
    }
    void modify_info()
    {
        cout << "Please input the No you want to make change\n";
        string num;
        cin >> num;
        cout << "Please input the attribute you want to change\n";
        vector<string> meta_data = gb_vol.get_vol_meta();
        for (int i = 0; i < meta_data.size(); i++)
        {
            cout << i + 1 << "." << meta_data[i] << "\n";
        }
        int opr;
        cin >> opr;
        cout << "Please input the new attribute\n";
        string attrr;
        cin >> attrr;
        gb_vol.modify_attr(num, opr, attrr);
    }
};
admin::admin(){};
admin::~admin(){};

class supervisor
{
  private:
  public:
    supervisor();
    ~supervisor();
    int display_func()
    {
        cout << "0. Exit system\n";
        cout << "1. Add new volunteer\n";
        cout << "2. Display volunteer info\n";
        cout << "3. Search volunteer info\n";
        cout << "4. Add new job\n";
        int opr;
        cin >> opr;
        return opr;
    }
    void add_volunteer()
    {
        cout << "Now adding new volunteer...\n";
        vector<string> meta_data = gb_vol.get_vol_meta();
        vector<string> new_piece;
        for (auto it : meta_data)
        {
            cout << "Now input " << it << " \n";
            string in;
            cin >> in;
            new_piece.push_back(in);
        }
        gb_vol.add_new_vol(new_piece);
        cout << "New user " << new_piece[0] << " has been added";
        cout << "Default password is " << gb_user.add_new_vol(new_piece[0]) << "\n";
    }
    void list_all_vol()
    {
        gb_vol.list_all_vol();
    }
    void filter_vol()
    {
        cout << "Please input the key you want to filter by\n";
        vector<string> meta_data = gb_vol.get_vol_meta();
        for (int i = 0; i < meta_data.size(); i++)
        {
            cout << i + 1 << "." << meta_data[i] << "\n";
        }
        int opr;
        cin >> opr;
        cout << "Please input the <key,value>\n";
        string tag;
        cin >> tag;

        gb_vol.filter_vol(opr - 1, tag);
    }
    void add_job()
    {
        cout << "Adding new job...\n";
        string in_title, in_desc;
        cout << "Now input the job title\n";
        cin >> in_title;
        cout << "Now input the job description\n";
        cin >> in_desc;
        gb_job.add_job(in_title, in_desc);
    }
    void modify_info()
    {
        cout << "Please input the No you want to make change\n";
        string num;
        cin >> num;
        cout << "Please input the attribute you want to change\n";
        vector<string> meta_data = gb_vol.get_vol_meta();
        for (int i = 0; i < meta_data.size(); i++)
        {
            cout << i + 1 << "." << meta_data[i] << "\n";
        }
        int opr;
        cin >> opr;
        cout << "Please input the new attribute\n";
        string attrr;
        cin >> attrr;
        gb_vol.modify_attr(num, opr, attrr);
    }
};
supervisor::supervisor(){};
supervisor::~supervisor(){};

class vol_restricted
{
  private:
    vector<pair<string, string>> vol_view;

  public:
    vol_restricted(string ser_num);
    ~vol_restricted();
    int display_func()
    {
        cout << "0. Exit system\n";
        cout << "1. Display personal info\n";
        cout << "2. Sign for a job\n";
        cout << "3. Complete my infomation\n";
        int opr;
        cin >> opr;
        return opr;
    }
    void display_info()
    {
        for (auto it : vol_view)
        {
            cout << it.first << "    ";
        }
        cout << "\n";
        for (auto it : vol_view)
        {
            cout << it.second << " ";
        }
        cout << "\n";
    }
    void sign_job()
    {
        cout << "The current jobs are:";
        gb_job.list_job();
        cout << "Please input the number you want to sign\n";
        int num;
        cin >> num;
        cout << "You have signed successfully\n";
    }
    void fill_info()
    {
        for (int i = 0; i < vol_view.size(); i++)
        {
            if (vol_view[i].second == "null")
            {
                cout << "Your attribute " << vol_view[i].first << " is missing, Please fill it\n";
                string in;
                cin >> in;
                vol_view[i].second = in;
                gb_vol.modify_attr(vol_view[0].second, i, in);
                cout << "Updated!\n";
            }
        }
        cout << "\n";
    }
};
vol_restricted::vol_restricted(string ser_num)
{
    vol_view = gb_vol.get_vol_info(ser_num);
};
vol_restricted::~vol_restricted(){};

void migrate_init()
{
    cout << "If this is your first time use this system, input 1 for system migration otherwise input something else "
            "you like\n";
    int op;
    cin >> op;
    if (op == 1)
    {
        cout << "Migrating the system\n";
        cout << "Default users are\n";
        cout << "Username    Password\n";
        cout << "admin    123456\n";
        cout << "supervisor    123456\n";
        gb_user.add_new_admin("admin");
        gb_user.add_new_sup("supervisor");
        gb_user.write_user_login_info();
        gb_vol.add_new_cons("Ser_no"); // primary key
        gb_vol.add_new_cons("Name");
        gb_vol.add_new_cons("Dept");
        gb_vol.add_new_cons("Mobile");
        gb_vol.write_vol_info();
        cout << "Migrate Successfully, Please reboot the system\n";
        exit(0);
    }
    else
    {
        cout << "Pass migration\n";
    }
}
void sys_init()
{
    cout << "System initilizing...\n";
    gb_user.read_user_login_info();
    gb_vol.read_vol_info();
    gb_job.read_job_info();
}

int main()
{
    migrate_init();
    sys_init();
    pair<int, string> user_type;
    while (user_type = gb_user.login(), !user_type.first)
    {
    }
    if (user_type.first == 1)
    {
        admin adm;
        int opr_type;
        while (opr_type = adm.display_func(), opr_type)
        {
            if (opr_type == 1)
            {
                adm.add_constraint();
            }
            else if (opr_type == 2)
            {
                adm.list_all_vol();
            }
            else if (opr_type == 3)
            {
                adm.filter_vol();
            }
        }
    }
    else if (user_type.first == 2)
    {
        supervisor sup;
        int opr_type;
        while (opr_type = sup.display_func(), opr_type)
        {
            if (opr_type == 1)
            {
                sup.add_volunteer();
            }
            else if (opr_type == 2)
            {
                sup.list_all_vol();
            }
            else if (opr_type == 3)
            {
                sup.filter_vol();
            }
            else if (opr_type == 4)
            {
                sup.add_job();
            }
        }
    }
    else if (user_type.first == 3)
    {
        vol_restricted vor(user_type.second);
        int opr_type;
        while (opr_type = vor.display_func(), opr_type)
        {
            if (opr_type == 1)
            {
                vor.display_info();
            }
            else if (opr_type == 2)
            {
                vor.sign_job();
            }
            else if (opr_type == 3)
            {
                vor.fill_info();
            }
        }
    }
    gb_user.write_user_login_info();
    gb_vol.write_vol_info();
    gb_job.write_job_info();
    return 0;
}