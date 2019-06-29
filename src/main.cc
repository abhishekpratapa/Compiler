#include <iostream>
#include <boost/program_options.hpp>

using namespace boost::program_options;

int main(int argc, char *argv[]) {
  try {
    options_description desc("Options");
    desc.add_options() 
      ("help", "Print help messages") 
      ("add", "additional options") 
      ("like", "this");

    variables_map vm;
    try 
    { 
      store(parse_command_line(argc, argv, desc), vm);
      if ( vm.count("help")  ) 
      { 
        std::cout << "Basic Command Line Parameter App" << std::endl 
                  << desc << std::endl; 
        return 0; 
      } 
      notify(vm);
    } 
    catch(error& e) 
    { 
      std::cerr << "ERROR: " << e.what() << std::endl << std::endl; 
      std::cerr << desc << std::endl; 
      return 1; 
    } 
  } catch (const error &ex) {
    std::cerr << "failed to parse arguments \n";
  }
  return 0;
}
