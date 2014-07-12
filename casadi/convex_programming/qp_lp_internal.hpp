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

#ifndef CASADI_QP_LP_INTERNAL_HPP
#define CASADI_QP_LP_INTERNAL_HPP

#include "casadi/core/function/lp_internal.hpp"
#include "casadi/core/function/qp_solver.hpp"

#include "qp_lp_solver.hpp"

/// \cond INTERNAL
namespace casadi {

  /** \brief Internal class for QPLPInternal
   *
      @copydoc LPSolver_doc
   * */
class CASADI_LPSOLVER_QP_EXPORT QPLPInternal : public LPSolverInternal {
  friend class QPLPSolver;
public:

  /** \brief  Create a new Solver */
  explicit QPLPInternal(const std::vector<Sparsity> &st);

  /** \brief  Destructor */
  virtual ~QPLPInternal();

  /** \brief  Clone */
  virtual QPLPInternal* clone() const;

  /** \brief  Create a new QP Solver */
  static LPSolverInternal* creator(const LPStructure& st)
  { return new QPLPInternal(st);}

  /** \brief  Initialize */
  virtual void init();

  virtual void evaluate();

  protected:
    QPSolver qpsolver_;

};

} // namespace casadi
/// \endcond

#endif // CASADI_QP_LP_INTERNAL_HPP

