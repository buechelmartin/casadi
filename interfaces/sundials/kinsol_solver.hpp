/*
 *    This file is part of CasADi.
 *
 *    CasADi -- A symbolic framework for dynamic optimization.
 *    Copyright (C) 2010 by Joel Andersson, Moritz Diehl, K.U.Leuven. All rights reserved.
 *
 *    CasADi is free software; you can redistribute it and/or
 *    modify it under the terms of the GNU Lesser General Public
 *    License as published by the Free Software Foundation; either
 *    version 3 of the License, or (at your option) any later version.
 *
 *    CasADi is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *    Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public
 *    License along with CasADi; if not, write to the Free Software
 *    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef KINSOL_SOLVER_HPP
#define KINSOL_SOLVER_HPP

#include "casadi/fx/implicit_function.hpp"

namespace CasADi{
namespace Sundials{
  
// Forward declaration of internal class 
class KinsolInternal;

/** \brief Kinsol solver class
*
* You can provide an initial guess by setting output(0).\n
* A good initial guess may be needed to avoid errors like "The linear solver's setup function failed in an unrecoverable manner."
*
* Available options:\n
* addOption("linear_solver", OT_STRING, "dense");\n
  addOption("upper_bandwidth", OT_INTEGER);\n
  addOption("lower_bandwidth", OT_INTEGER);\n
  addOption("max_krylov", OT_INTEGER, 0);\n
  addOption("exact_jacobian", OT_BOOLEAN, true);\n
  addOption("iterative_solver",OT_STRING,"gmres");\n
  addOption("f_scale",OT_REALVECTOR); Scaling factors on equations\n
  addOption("u_scale",OT_REALVECTOR); Scaling factors on variables\n
  addOption("constraints",OT_INTEGERVECTOR);\n
  
  The constraints option expects an integer entry for each variable u:\n
    
  0 then no constraint is imposed on u. \n
  1 then ui will be constrained to be u >= 0.0. \n
 −1 then ui will be constrained to be ui >= 0.0. \n
  2 then ui will be constrained to be ui > 0.0. \n
  −2 then ui will be constrained to be ui < 0.0. \n

*
* \see ImplicitFunction for more information
* 
*/
class KinsolSolver : public ImplicitFunction{
public:

  /** \brief  Default constructor */
  KinsolSolver();
  
  /** \brief  Create an KINSOL instance
   *  
   * \param f SXFunction mapping from (n+1) inputs to 1 output
   *
   */
  explicit KinsolSolver(const FX& f, int nrhs=1);
  
  /** \brief  Access functions of the node */
  KinsolInternal* operator->();

  /** \brief  Const access functions of the node */
  const KinsolInternal* operator->() const;

  /// Check if the node is pointing to the right type of object
  virtual bool checkNode() const;
  
  /** \brief Generate a linear solver for the sensitivity equations */
  KinsolSolver jac(int iind=0, int oind=0);

};


} // namespace Sundials
} // namespace CasADi

#endif //KINSOL_SOLVER_HPP

