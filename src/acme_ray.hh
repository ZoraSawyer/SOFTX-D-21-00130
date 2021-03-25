/*
(***********************************************************************)
(*                                                                     *)
(* The acme computational geometry library                             *)
(* Release Version 0.0.0                                               *)
(* Copyright (c) 2020-2021 Davide Stocco, All Rights Reserved.         *)
(*                                                                     *)
(* The acme computational geometry library and its components are      *)
(* supplied under the terms of the open source MIT License.            *)
(* The contents of the acme computational geometry library and its     *)
(* components may not be copied or disclosed except in accordance with *)
(* the terms of the MIT License.                                       *)
(*                                                                     *)
(* URL: https://opensource.org/licenses/MIT                            *)
(*                                                                     *)
(***********************************************************************)
*/

///
/// file: acme_ray.hh
///

#ifndef INCLUDE_ACME_RAY
#define INCLUDE_ACME_RAY

#include "acme.hh"
#include "acme_math.hh"

namespace acme
{

  /*\
   |                   
   |   _ __ __ _ _   _ 
   |  | '__/ _` | | | |
   |  | | | (_| | |_| |
   |  |_|  \__,_|\__, |
   |             |___/ 
  \*/

  //! Ray class container
  /*!
  Infinite ray in 3D space and defined by any point lying on the line and a direction
  vector.
  */
  class ray
  {
  private:
    vec3 _origin;    //!< Origin
    vec3 _direction; //!< Direction

  public:
    //! Class destructor
    ~ray() {}

    //! Class constructor
    ray() {}

    //! Copy constructor
    ray(ray const &) = default;

    //! Class constructor
    ray(
        real_type const ox, //<! Input x origin value
        real_type const oy, //<! Input y origin value
        real_type const oz, //<! Input z origin value
        real_type const dx, //<! Input x direction value
        real_type const dy, //<! Input y direction value
        real_type const dz  //<! Input z direction value
        ) : _origin(vec3(ox, oy, oz)), _direction(vec3(dx, dy, dz))
    {
    }

    //! Class constructor
    ray(
        vec3 const &origin,   //!< Input origin
        vec3 const &direction //!< Input direction
        ) : _origin(origin), _direction(direction)
    {
    }

    //! Equality operator
    ray &operator=(
        ray const &input //!< Input object
    );

    //! Check if objects are (almost) equal
    bool is_equal(
        ray const &input //!< Input object
    ) const;

    //! Check if ray is degenerated
    bool is_degenerated(void) const;

    //! Return origin
    vec3 const &origin() const;

    //! Return direction
    vec3 const &direction() const;

    //! Set origin
    void origin(
        vec3 const &input //!< input object
    );

    //! Set direction
    void direction(
        vec3 const &input //!< input object
    );

    //! Translate by vector
    void translate(
        vec3 const &input //!< Input
    );

    //! Rotate by matrix
    void rotate(
        mat3 const &input //!< Input
    );

    //! Reverse direction
    void reverse(void);

    //! Get reversed ray
    ray reversed(void) const;

    // Check whether the point is inside the ray
    bool is_inside(
        vec3 const &point //!< Input
    ) const;

  }; // class ray

  static ray const NaN_ray = ray(acme::NaN_vec3, acme::NaN_vec3); //!< Not-a-Number ray type
  static ray ray_goat = ray(NaN_ray);                           //!< Scapegoat ray type (throwaway non-const object)

} // namespace acme

#endif

///
/// eof: acme_ray.hh
///