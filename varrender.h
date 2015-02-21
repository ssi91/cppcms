class VarRender
{
	private:
		string templ;
		string *varname;
		string *varval;
		int count_vars;
		bool global;
	public:
		VarRender(const string &_templ, bool _global = false);

		void initVar(const &_varname, const &_varval = "");
		string getTemplName();
		vector<string> getVars();
		vector<string> getVals();
};
