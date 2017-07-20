#pragma once

//namespace noware
//{
	//namespace machine
	//{
		// processor cpu
		// thread task job
		class cpu
			: public dev
		{
			public:
				// operator operation
				enum class opr
				{
					none,
					
					// For controlling the flow of the execution:
					//and,	// and intersection
					//or, // or union
					/*
					get,				// attainment obtainment get read load
					set,				// assignment settlement set write store move
					//exist,			// presence existence exist
					rm,					// removal resettal rm
					
					add,				// addition
					substr,			// substraction
					multi,			// multiplication
					div,				// division
					
					exp,				// exponentiation
					modulo,			// remainder of division
					modulus,		// absolute value
					complement,	// complement compl
					
					cat					// concatenation cat
					*/
					
					set,
					
					// Control of the flow
					//eql,
					//grtr,
					//grtr_eql,
					//lowr,
					//lowr_eql,
					
					//output,		// output set echo
					go			// go[[ ]to] skip jump hop
				};
				
				class instr
					: public noware::serial
				{
					public:
						instr (void);
						instr (const std::string &/* other*/);
						virtual ~instr (void);
						
						virtual const instr & operator = (const instr &/* other*/);
						virtual const std::string & operator = (const std::string &/* other*/);
						virtual operator const std::string (void) const;
						
						opr oprn;	// Optional.
						
						// operand
						// Convention for the move instruction.
						// oprnd [0] == source (always (should be) (enqueued as) a literal)
						// oprnd [1] == destination, key
						// oprnd [2] == destination, group
						//noware::var operand1;
						//noware::var operand2;	// Optional.
						std::string oprnd [2];
						//std::string oprnd [3];
						bool ref [2];
						
						// Does the source operand
						// represent a reference?
						// (or a literal?)
						//bool oprnd_src_ref;
						
						std::string thread_id;
						//bool reg;
						//noware::nr reg_nr;
						//noware::nr ndx;
						
						//dependents;	// Not really needed.
						//dependencies;
						
						// evaluate value val
						//const bool operator== (const instruction &/* other*/) const;
						virtual const std::string /*e*/val/*uate*/ (void) const;
						
						
						friend class boost::serialization::access;
						
						template <typename archive>
						void serialize (archive &, const unsigned int &/* version*/);
					public:
						// TODO
						// 
						// inherit these two functions
						// from noware::serial
						// (do not reimplement)
						virtual const std::string serialize (void) const;
						virtual const bool deserialize (const std::string &/* serial*/);
				};
				
				cpu (void);
				virtual ~cpu (void);
				
				static const std::string grp_dft;
				
				virtual const bool stop (void);
				virtual const bool status (void) const;
				virtual const bool start (void);
				
				virtual const bool load (const std::string &/* file_name*/);
				
				// Queue
			public:
			//protected:
				// dequeue beginning first head top pop next fetch operate
				virtual const instr next_dequeue (void);
				virtual const instr next (void) const;
				virtual const bool dequeue (void);
				//const instruction dequeue (void);
			public:
				virtual const noware::nr size (void) const;
				virtual const bool empty (void) const;
				virtual const bool full (void) const;
				
				virtual const bool enqueue (const instr &);
				//const bool enqueue (const operation &/* operator*/, const noware::var &/* operand1*/, const noware::var &/* operand2*/ = "");	// Accurate.
				virtual const bool enqueue (const std::string &/* operand1 (source)*/, const opr &/* operation*/ = opr::none, const std::string &/* operand2 (key)*/ = "", const std::string &/* operand3/thread_id (group)*/ = "");	// Convenient.
				// do perform execute apply evaluate
				//const bool apply (const instruction &);
				
				// Store
			public:
				virtual const bool exist (const std::string &/* key*/) const;
				virtual const bool exist (const std::string &/* group*/, const std::string &/* key*/) const;
				
				virtual const bool clear (void);
				virtual const bool clear (const std::string &/* group*/);
				
				virtual const bool remove (const std::string &/* group*/, const std::string &/* key*/);
				virtual const bool remove (const std::string &/* key*/);
				
				virtual const std::string/* value*/ get (const std::string &/* group*/, const std::string &/* key*/) const;
				virtual const std::string/* value*/ get (const std::string &/* key*/) const;
				//virtual const std::pair <std::string/* value*/, bool/* reference*/> get (const std::string &/* group*/, const std::string &/* key*/) const;
				//virtual const std::pair <std::string/* value*/, bool/* reference*/> get (const std::string &/* key*/) const;
				
				virtual const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/);
				virtual const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/);
				//virtual const bool/* success*/ set (const std::string &/* group*/, const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
				//virtual const bool/* success*/ set (const std::string &/* key*/, const std::string &/* content/value*/, const bool &/* reference*/ = false);
			protected:
				//virtual const bool/* success*/ respond (const zyre_event_t */* (zyre) event*/, const std::string &/* event_type*/, const zmq::msg &/* rx'd*/, zmq::msg &/* response*/);
				virtual const bool/* success*/ search (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				//virtual const bool/* success*/ search_local (zmq::msg &/* result*/, const zmq::msg &/* message/expression*/);// const
				//virtual const zmq::msg/* result*/ aggregate (const zmq::msg &/* result*/, const noware::nr &/* responses_count*//* number of peers who answered*/, const zmq::msg &/* response*/, const zmq::msg &/* expression*/);
			protected:
				// Process/Find/Search for/ the next instruction on-the-fly.
				// Do not store an instruction queue.
				//std::queue <instruction> queue;
			protected:
				//bool running;
				
				// 'EXEcutioN' thread
				// For running "void exe (void)".
				boost::thread * exen;
				
				// executer of instructions
				void exe (void);
				
				//// redundancy group
				//std::string grp;
		};
	//}
//}

/*
	{
		(ins(req()));
		(ins(req()));
		(ins(req()));
	}
*/

/*
	activity
	{
		process (exp (ins));
		process (exp (ins));
		process (exp (ins));
	}
*/

/*
*/
