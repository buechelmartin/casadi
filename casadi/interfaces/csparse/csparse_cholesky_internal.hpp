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

#ifndef CASADI_CSPARSE_CHOLESKY_INTERNAL_HPP
#define CASADI_CSPARSE_CHOLESKY_INTERNAL_HPP

/// \cond INTERNAL

extern "C" {
#include "external_packages/CSparse/Include/cs.h"
}

#include "csparse_cholesky.hpp"
#include "casadi/core/function/linear_solver_internal.hpp"

namespace casadi {

  /**
     @copydoc LinearSolver_doc
  */
  class CASADI_LINEARSOLVER_CSPARSECHOLESKY_EXPORT
  CSparseCholeskyInternal : public LinearSolverInternal {
  public:
    // Create a linear solver given a sparsity pattern and a number of right hand sides
    CSparseCholeskyInternal(const Sparsity& sp, int nrhs);

    // Copy constructor
    CSparseCholeskyInternal(const CSparseCholeskyInternal& linsol);

    /** \brief  Create a new LinearSolver */
    static LinearSolverInternal* creator(const Sparsity& sp, int nrhs)
    { return new CSparseCholeskyInternal(sp, nrhs);}

    // Destructor
    virtual ~CSparseCholeskyInternal();

    // Initialize the solver
    virtual void init();

    // Factorize the matrix
    virtual void prepare();

    // Solve the system of equations
    virtual void solve(double* x, int nrhs, bool transpose);

    // Solve the system of equations <tt>Lx = b</tt>
    void solveL(double* x, int nrhs, bool transpose);

    /// Obtain a symbolic Cholesky factorization
    Sparsity getFactorizationSparsity(bool transpose=false) const;

    /// Obtain a numeric Cholesky factorization
    DMatrix getFactorization(bool transpose=false) const;

    // Clone
    virtual CSparseCholeskyInternal* clone() const;

    // The transpose of linear system in form (CCS)
    cs AT_;

    // The symbolic factorization
    css *S_;

    // The numeric factorization
    csn *L_;

    // Temporary
    std::vector<double> temp_;


  };

} // namespace casadi
/// \endcond
#endif // CASADI_CSPARSE_CHOLESKY_INTERNAL_HPP

