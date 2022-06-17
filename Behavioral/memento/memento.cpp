#include <string>
#include <memory>
#include <iostream>

class Snapshot
{
public:
    Snapshot(const std::string& data, const std::string& created): backup(data), date(created) {}
private:
    friend class SourceFile;
    const std::string& getBackup() const
    {
        return backup;
    }

    std::string backup;
    std::string date;
};

class SourceFile
{
public:
    SourceFile() 
    {}

    void addText(const std::string& text)
    {
        data.append(text);
    }

    std::string getText() const
    {
        return data;
    }

    std::shared_ptr<Snapshot> makeSnapshot() const
    {
        return std::make_shared<Snapshot>(data, std::string{"Today"});
    }

    void restore(std::shared_ptr<Snapshot> snapshot)
    {
        data = snapshot->getBackup();
    }
    
private:
    std::string data;
};

int main()
{
    SourceFile src{};
    src.addText("Hello ");
    auto snapshot = src.makeSnapshot();
    src.addText("World ");
    src.addText("Patterns");

    std::cout<<src.getText()<<std::endl;
    src.restore(snapshot);
    std::cout<<src.getText()<<std::endl;
}