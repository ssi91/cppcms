#ifndef VARRENDER_H
#define VARRENDER_H
class VarRender
{
	private:
		string templ;
		string *varname;
		string *varval;
		size_t count;
		bool global;
	public:
		VarRender(const string _templ = NULL, bool _global = false);

		VarRender(VarRender &a)

		void initVar(const &_varname, const &_varval = "");
		string getTemplName();
		vector<string> getVars();
		vector<string> getVals();
		string getVals(string);
		size_t getCount();
		bool isGlobal();
};
#endif
