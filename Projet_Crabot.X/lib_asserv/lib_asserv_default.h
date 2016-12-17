#ifndef _LIB_ASSERV_DEFAULT_H_
#define _LIB_ASSERV_DEFAULT_H_

#ifndef NULL
#define NULL 0
#endif


/*############################################################################*/
/*                                  Motion                                    */
/*############################################################################*/

// {v, vt} v = 0.9 * v max moteur, vt = v/(entre roues/2)
#ifndef DEFAULT_CONSTRAINT_V_MAX
#define DEFAULT_CONSTRAINT_V_MAX {0.9, 7.03}
#endif

/* {a, at, v_vt} a = a max sans glissement, at = a/(entre roues/2),
 * v_vt = acc centripete (trop fort -> erreur odo) 0.1g
 */
#ifndef DEFAULT_CONSTRAINT_A_MAX
#define DEFAULT_CONSTRAINT_A_MAX {2, 15.6, 0.981}
#endif

#ifndef BLOCK_LIMIT // 5s
#define BLOCK_LIMIT 500
#endif

/*############################################################################*/
/*                                    Odo                                     */
/*############################################################################*/

#ifndef DEFAULT_ODO_COEFS // {tic/m, m/tic, entre roues}
#define DEFAULT_ODO_COEFS {54327, 0.000018407, 0.25598}    // {54327, 0.000018407, 0.25598}
#endif

#ifndef DEFAULT_PERIOD
#define DEFAULT_PERIOD 0.010
#endif

/*############################################################################*/
/*                                  Asserv                                    */
/*############################################################################*/

#ifndef DEFAULT_ASSERV_MODE
#define DEFAULT_ASSERV_MODE ASSERV_MODE_OFF
#endif
#ifndef DEFAULT_STOP_DISTANCE
#define DEFAULT_STOP_DISTANCE 0.002 // +-2mm
#endif
#ifndef DEFAULT_STOP_ANGLE // en radian
#define DEFAULT_STOP_ANGLE 0.03491// +-2deg
#endif

/*############################################################################*/
/*                                   PID                                      */
/*############################################################################*/

// 2 PID lies a l'asserve en position (delta: position absolue, alpha: position angulaire)
#ifndef DEFAULT_PID_POS_COEFS_DELTA // {kp, ki, kd, mu_p}
#define DEFAULT_PID_POS_COEFS_DELTA {7,0,130,1} // {7,0,80,1}
#endif
#ifndef DEFAULT_PID_POS_COEFS_ALPHA // {kp, ki, kd, mu_p}
#define DEFAULT_PID_POS_COEFS_ALPHA {17,0,220,1} // {17,0,220,1}
#endif

// 2 PID lies a l'asserve en vitesse (delta: vitesse absolue, alpha: vitesse angulaire)
#ifndef DEFAULT_PID_COEFS_DELTA // {kp, ki, kd, mu_p}
#define DEFAULT_PID_COEFS_DELTA {110,10,0,1} // {110,10,0,1}
#endif
#ifndef DEFAULT_PID_COEFS_ALPHA // {kp, ki, kd, mu_p}
#define DEFAULT_PID_COEFS_ALPHA {14,1,0,1} //  {14,1,0,1}
#endif

/* valeurs max de l'intégrale en vitesse et vitesse angulaire
 *  (pas trop petit sinon on atteint pas la vitesse demand�e,
 *   on pourrait trouver une meilleur borne sup)
 */
#ifndef DEFAULT_PID_MAX_INT_DELTA
#define DEFAULT_PID_MAX_INT_DELTA 1000
#endif
#ifndef DEFAULT_PID_MAX_INT_ALPHA
#define DEFAULT_PID_MAX_INT_ALPHA 1000
#endif

/* conditions d'arrêt des PID en vitesse et vitesse angulaire
 * (empiriques, ne pas trop toucher)
 */
#ifndef DEFAULT_PID_EPS_DELTA
#define DEFAULT_PID_EPS_DELTA {0.015,0.015}
#endif
#ifndef DEFAULT_PID_EPS_ALPHA
#define DEFAULT_PID_EPS_ALPHA {0.15,0.15}
#endif

/*############################################################################*/
/*                                  DEBUG                                     */
/*############################################################################*/

#ifndef DEFAULT_DEBUG_MODE
#define DEFAULT_DEBUG_MODE 0
#endif

#endif // _LIB_ASSERV_DEFAULT_H_
