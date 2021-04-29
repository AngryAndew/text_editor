#include "ECDocument.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

Document::Document(ECEditorView& view) : view(view), lines{""}
{}


void Document::insert(int x, int y, const std::string& str)
{
    lines[y].insert(x, str);
    update();
}
void Document::new_line(int x, int y)
{
    std::string str = lines[y].substr(x);
    lines.insert(lines.begin() + y + 1, str);
    lines[y] = lines[y].substr(0, x);
    update();
}

char Document::del(int x, int y)
{
    char c = lines[y][x];
    lines[y].erase(lines[y].begin() + (x));
    update();
    return c;
}

int Document::join_line(int x, int y)
{
    int px = 0;
    if(y > 0)
    {
        px = lines[y - 1].size();
        lines[y - 1] += lines[y];
        lines.erase(lines.begin() + y);
        update();
    }
    return px;
}

void Document::update()
{
    view.update(lines);
}

int Document::line_size(int y)
{
    return lines[y].size();
}

void Document::load_file(std::string filename)
{
    std::fstream newfile(filename, std::ios::in);
    if (newfile.is_open())
    {   
        lines.clear();
        std::string line;
        while(getline(newfile, line))
        { 
            lines.push_back(line);
        } 
        update();
        newfile.close(); 
    }
}
void Document::save_file(std::string filename)
{
    std::fstream newfile(filename, std::ios::out);
     if(newfile.is_open())     
   {
       for(auto &line : lines)
       {
           newfile << line << "\n"; 
       }
      newfile.close(); 
   }
}

int Document::total_lines()
{
    return lines.size();
}

std::vector<int> Document::find_string(std::string str)
{
    std::vector<int> five;
   for (int i = 0; i < lines.size(); i++)
   {
       int j = 0;
       while (j < lines[i].size())
       {
        j = lines[i].find(str, j);
        if (j >= 0)
        {
            five.push_back(j);
            j += str.size();
        }
        else
        {
            break;
        }
       }
   }
   return five;
}

void Document::replace(int x, int y, std::string status, std::string text)
{
    std::vector<int> five;
    five = find_string(status);
    for (int i = five.size(); i --> 0;)
    {
        lines[y].replace(five[i], status.size() , text);
    }
    update();
}