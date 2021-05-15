#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'sumPathsOfLengthN' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER num
 *  2. STRING edges
 */

void print_graph(unordered_map<char, unordered_set<char>> graph) {
    for (auto x : graph) {
        cout << x.first << " to ";
        for (auto y : x.second) {
            cout << y << " ";
        }
        cout << endl;
    }
}






int arr_to_int(vector<char> arr, int n) {
    string num;
    for (int i = 0; i < n; i++) {
        num += arr[i];
    }
    return stoi(num);
}

int total = 0;
void get_path(unordered_map<char, unordered_set<char>> map, char v, vector<char> path, int len_of_path, int num) {
    if ((count(path.begin(), path.end(), v) == 1 && path[path.size()-1] != v) || count(path.begin(), path.end(), v) >= 2) {
        return;
    }
    if (len_of_path == num) {
        total += arr_to_int(path, num);
        // cout << "Path: " << arr_to_int(path, num) << endl;
        return;
    }
    for (char i : map[v]) {
        path.push_back(i);
        get_path(map, i, path, len_of_path+1, num);
        path.pop_back();
    }
}
int sumPathsOfLengthN(int num, string edges) {
    int output = 0;
    num++;
    unordered_map<char, unordered_set<char>> graph;
    int total_nodes = 0;
    for (int i = 0; i < edges.length(); i += 3) {
        graph[edges[i]].insert(edges[i+1]);
        total_nodes = max(total_nodes, max(edges[i]-'0', edges[i+1]-'0'));
    }
    // print_graph(graph);
    // int total_nodes = graph.size();
    // cout << "Total Nodes: " << total_nodes << '\n';
    for (int i = 1; i <= total_nodes; i++) {
        vector<char> empty_path; empty_path.push_back('0'+i);
        get_path(graph, '0'+i, empty_path, 1, num);
    }
    return total;
}




int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));

    string num_temp;
    getline(cin, num_temp);

    int num = stoi(ltrim(rtrim(num_temp)));

    string edges;
    getline(cin, edges);

    int result = sumPathsOfLengthN(num, edges);

    cout << result << "\n";

    // fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
