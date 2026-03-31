#include <fstream>
#include <iostream>
#include <string>

static void replace_all_and_write(std::istream& in,
                                 std::ostream& out,
                                 const std::string& s1,
                                 const std::string& s2)
{
    const std::size_t chunkSize = 4096;
    std::string buffer;
    std::string chunk;
    chunk.resize(chunkSize);

    while (in)
    {
        in.read(&chunk[0], static_cast<std::streamsize>(chunkSize));
        std::streamsize got = in.gcount();
        if (got <= 0)
            break;

        buffer.append(chunk, 0, static_cast<std::size_t>(got));

        std::size_t safeLen = buffer.size();
        if (s1.size() > 1 && safeLen >= (s1.size() - 1))
            safeLen = buffer.size() - (s1.size() - 1);
        else
            safeLen = 0;

        std::size_t pos = 0;
        while (pos < safeLen)
        {
            std::size_t found = buffer.find(s1, pos);
            if (found == std::string::npos || found >= safeLen)
                break;
            out << buffer.substr(pos, found - pos);
            out << s2;
            pos = found + s1.size();
        }

        if (pos > 0)
            buffer.erase(0, pos);

        if (buffer.size() > chunkSize * 4)
        {
            if (buffer.size() > s1.size())
            {
                out << buffer.substr(0, buffer.size() - s1.size());
                buffer.erase(0, buffer.size() - s1.size());
            }
        }
    }
    std::size_t pos = 0;
    while (true)
    {
        std::size_t found = buffer.find(s1, pos);
        if (found == std::string::npos)
            break;
        out << buffer.substr(pos, found - pos);
        out << s2;
        pos = found + s1.size();
    }
    out << buffer.substr(pos);
}

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }

    const std::string filename = argv[1];
    const std::string s1 = argv[2];
    const std::string s2 = argv[3];

    if (filename.empty())
    {
        std::cerr << "Error: filename is empty" << std::endl;
        return 1;
    }
    if (s1.empty())
    {
        std::cerr << "Error: s1 must not be empty" << std::endl;
        return 1;
    }

    std::ifstream in(filename.c_str());
    if (!in)
    {
        std::cerr << "Error: can't open input file: " << filename << std::endl;
        return 1;
    }

    const std::string outName = filename + ".replace";
    std::ofstream out(outName.c_str());
    if (!out)
    {
        std::cerr << "Error: can't open output file: " << outName << std::endl;
        return 1;
    }

    replace_all_and_write(in, out, s1, s2);

    if (!out)
    {
        std::cerr << "Error: write failed" << std::endl;
        return 1;
    }

    return 0;
}
