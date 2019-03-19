#include <getopt.h>

#include "Configuration.h"
#include "Search/RegularSearch/RegularSearch.h"
#include "Search/RegexSearch/RegexSearch.h"
#include "FileReader/Text/TextReader.h"
#include "FileSystem/Local/LocalFile.h"
#include "FileSystem/Local/LocalDirectory.h"
#include "Style/Ack/Ack.h"

Configuration* Configuration::m_instance = nullptr;

Configuration* Configuration::getInstance(int argc, char** argv)
{
    if (!m_instance)
    {
        m_instance = new Configuration(argc, argv);
    }

    return m_instance;
}

Configuration::Configuration(int argc, char** argv)
{
    if (argc > 1)
    {
        m_searchText = argv[1];
    }

    m_files = argc > 2 ? argv[2] : ".";

    m_beforeContext = argc > 3 ? std::stoi(argv[3]) : 0;
    m_afterContext  = argc > 4 ? std::stoi(argv[4]) : 0;

    m_extensionMatch = new ExtensionMatch;

    m_extensionMatch->add("as");
    m_extensionMatch->add("mxml");
    m_extensionMatch->add("ada");
    m_extensionMatch->add("adb");
    m_extensionMatch->add("ads");
    m_extensionMatch->add("asm");
    m_extensionMatch->add("s");
    m_extensionMatch->add("asp");
    m_extensionMatch->add("master");
    m_extensionMatch->add("ascx");
    m_extensionMatch->add("asmx");
    m_extensionMatch->add("aspx");
    m_extensionMatch->add("svc");
    m_extensionMatch->add("bat");
    m_extensionMatch->add("cmd");
    m_extensionMatch->add("c");
    m_extensionMatch->add("h");
    m_extensionMatch->add("xs");
    m_extensionMatch->add("cfc");
    m_extensionMatch->add("cfm");
    m_extensionMatch->add("cfml");
    m_extensionMatch->add("clj");
    m_extensionMatch->add("txt");
    m_extensionMatch->add("cmake");
    m_extensionMatch->add("coffee");
    m_extensionMatch->add("cpp");
    m_extensionMatch->add("cc");
    m_extensionMatch->add("cxx");
    m_extensionMatch->add("m");
    m_extensionMatch->add("hpp");
    m_extensionMatch->add("hh");
    m_extensionMatch->add("h");
    m_extensionMatch->add("hxx");
    m_extensionMatch->add("cs");
    m_extensionMatch->add("css");
    m_extensionMatch->add("dart");
    m_extensionMatch->add("pas");
    m_extensionMatch->add("int");
    m_extensionMatch->add("dfm");
    m_extensionMatch->add("nfm");
    m_extensionMatch->add("dof");
    m_extensionMatch->add("dpk");
    m_extensionMatch->add("dproj");
    m_extensionMatch->add("groupproj");
    m_extensionMatch->add("bdsgroup");
    m_extensionMatch->add("bdsproj");
    m_extensionMatch->add("el");
    m_extensionMatch->add("ex");
    m_extensionMatch->add("exs");
    m_extensionMatch->add("erl");
    m_extensionMatch->add("hrl");
    m_extensionMatch->add("f");
    m_extensionMatch->add("f77");
    m_extensionMatch->add("f90");
    m_extensionMatch->add("f95");
    m_extensionMatch->add("f03");
    m_extensionMatch->add("for");
    m_extensionMatch->add("ftn");
    m_extensionMatch->add("fpp");
    m_extensionMatch->add("go");
    m_extensionMatch->add("groovy");
    m_extensionMatch->add("gtmpl");
    m_extensionMatch->add("gpp");
    m_extensionMatch->add("grunit");
    m_extensionMatch->add("gradle");
    m_extensionMatch->add("hs");
    m_extensionMatch->add("lhs");
    m_extensionMatch->add("h");
    m_extensionMatch->add("htm");
    m_extensionMatch->add("html");
    m_extensionMatch->add("java");
    m_extensionMatch->add("properties");
    m_extensionMatch->add("js");
    m_extensionMatch->add("json");
    m_extensionMatch->add("jsp");
    m_extensionMatch->add("jspx");
    m_extensionMatch->add("jhtm");
    m_extensionMatch->add("jhtml");
    m_extensionMatch->add("less");
    m_extensionMatch->add("lisp");
    m_extensionMatch->add("lsp");
    m_extensionMatch->add("lua");
    m_extensionMatch->add("mk");
    m_extensionMatch->add("mak");
    m_extensionMatch->add("m");
    m_extensionMatch->add("mkd");
    m_extensionMatch->add("md");
    m_extensionMatch->add("m");
    m_extensionMatch->add("h");
    m_extensionMatch->add("mm");
    m_extensionMatch->add("h");
    m_extensionMatch->add("ml");
    m_extensionMatch->add("mli");
    m_extensionMatch->add("pir");
    m_extensionMatch->add("pasm");
    m_extensionMatch->add("pmc");
    m_extensionMatch->add("ops");
    m_extensionMatch->add("pod");
    m_extensionMatch->add("pg");
    m_extensionMatch->add("tg");
    m_extensionMatch->add("pl");
    m_extensionMatch->add("pm");
    m_extensionMatch->add("pod");
    m_extensionMatch->add("t");
    m_extensionMatch->add("psgi");
    m_extensionMatch->add("t");
    m_extensionMatch->add("php");
    m_extensionMatch->add("phpt");
    m_extensionMatch->add("php3");
    m_extensionMatch->add("php4");
    m_extensionMatch->add("php5");
    m_extensionMatch->add("phtml");
    m_extensionMatch->add("pt");
    m_extensionMatch->add("cpt");
    m_extensionMatch->add("metadata");
    m_extensionMatch->add("cpy");
    m_extensionMatch->add("py");
    m_extensionMatch->add("pmc");
    m_extensionMatch->add("py");
    m_extensionMatch->add("R");
    m_extensionMatch->add("rb");
    m_extensionMatch->add("rhtml");
    m_extensionMatch->add("rjs");
    m_extensionMatch->add("rxml");
    m_extensionMatch->add("erb");
    m_extensionMatch->add("rake");
    m_extensionMatch->add("spec");
    m_extensionMatch->add("rs");
    m_extensionMatch->add("sass");
    m_extensionMatch->add("scss");
    m_extensionMatch->add("scala");
    m_extensionMatch->add("scm");
    m_extensionMatch->add("ss");
    m_extensionMatch->add("sh");
    m_extensionMatch->add("bash");
    m_extensionMatch->add("csh");
    m_extensionMatch->add("tcsh");
    m_extensionMatch->add("ksh");
    m_extensionMatch->add("zsh");
    m_extensionMatch->add("fish");
    m_extensionMatch->add("st");
    m_extensionMatch->add("sql");
    m_extensionMatch->add("ctl");
    m_extensionMatch->add("tcl");
    m_extensionMatch->add("itcl");
    m_extensionMatch->add("itk");
    m_extensionMatch->add("tex");
    m_extensionMatch->add("cls");
    m_extensionMatch->add("sty");
    m_extensionMatch->add("textile");
    m_extensionMatch->add("tt");
    m_extensionMatch->add("tt2");
    m_extensionMatch->add("ttml");
    m_extensionMatch->add("bas");
    m_extensionMatch->add("cls");
    m_extensionMatch->add("frm");
    m_extensionMatch->add("ctl");
    m_extensionMatch->add("vb");
    m_extensionMatch->add("resx");
    m_extensionMatch->add("v");
    m_extensionMatch->add("vh");
    m_extensionMatch->add("sv");
    m_extensionMatch->add("vhd");
    m_extensionMatch->add("vhdl");
    m_extensionMatch->add("vim");
    m_extensionMatch->add("xml");
    m_extensionMatch->add("dtd");
    m_extensionMatch->add("xsl");
    m_extensionMatch->add("xslt");
    m_extensionMatch->add("ent");
    m_extensionMatch->add("yaml");
    m_extensionMatch->add("yml");

    m_file       = new LocalFile;
    m_directory  = new LocalDirectory;
    m_reader     = new TextReader;
    m_search     = new RegularSearch;
    m_style      = new Ack;
    m_threadPool = new ThreadPool;
}

Configuration::~Configuration()
{
    m_threadPool->shutdown(true);

    delete m_threadPool;
    delete m_directory;
    delete m_file;
    delete m_reader;
    delete m_search;
    delete m_style;
    delete m_extensionMatch;
}