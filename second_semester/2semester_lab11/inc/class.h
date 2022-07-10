class codeGenerator
{
public:
    codeGenerator(){};
    std::string getCode(){
        return generateCode();
    }
protected:
    enum Lang {JAVA = 0, Cpp = 1, PHP = 2};
    Lang m_language;
    virtual std::string generateCode() = 0;
};

class generateJava: public codeGenerator
{
    std::string generateCode() override{
        return "code on Java";
    }
public:
    generateJava() { m_language = JAVA; }
    virtual ~generateJava(){};
};

class generateCpp: public codeGenerator
{
    std::string generateCode() override{
        return "code on Cpp";
    }
public:
    generateCpp() { m_language = Cpp; }
    virtual ~generateCpp(){};
};

class generatePHP: public codeGenerator
{
    std::string generateCode() override{
        return "code on PHP";
    }
public:
    generatePHP() { m_language = PHP; }
    virtual ~generatePHP(){};
};