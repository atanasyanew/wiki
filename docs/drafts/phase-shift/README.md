## Фази и фазови разлики

!> Work in process!

**notes:**
phase shift
http://macao.communications.museum/eng/exhibition/secondfloor/MoreInfo/2_4_4_PhaseShift.html
add figs
vector diagrams 
more explanations
**R**
$ i_R(t) = i_m sin(\omega t + \psi_{iR}) $
$ i_R(t) = i_m sin\theta_i $
$ \theta_i = \omega t + \psi_i $

$ u_R(t) = R * i(t) $

$ u_R(t) = R * i_m sin(\omega t + \psi_i) $
$ u_R(t) = R *  i_m sin\theta_{uR} $
$ \theta_{uR} = \omega t + \psi_{iR} $

$ \varphi = \theta_{uR} - \theta_{iR} $
$ \varphi = \omega t + \psi_{iR} - \omega t + \psi_{iR} $
$ \varphi = 0 $
$ \psi_u = \psi_i $

<br>

**L**
$$ i_L(t) = i_m sin(\omega t + \psi_{iL}) $$

$$ i_L(t) = i_m sin\theta_{iL} $$

$$ \theta_{iL} = \omega t + \psi_{iL} $$

$$ u_L(t) = L {di_L \over dt} $$

$$ u_L(t) = { {L \ d \left[ i_m sin ( \omega t + \psi_{iL} \right]) } \over dt} $$

$$ u_L(t) = L \ \omega \ i_m cos(\omega t + \psi_{iL} ) $$

$$ u_L(t) = L \ \omega \ i_m cos(\omega t + \psi_{iL} + {\pi \over 2} ) $$

$$ u_L(t) = L \ \omega \ i_m cos \theta_{uL} $$

$$ \theta_{uL} =  \omega t + \psi_{iL} + {\pi \over 2} $$

$$ \varphi = \theta_{uL} - \theta_{iL} $$

$$ \varphi = \omega t + \psi_{iL} - \omega t + \psi_{iL} + {\pi \over 2} $$

$$ \varphi = {\pi \over 2} $$

$$ \varphi > 0 $$ 
voltage overtakes the phase current with 90 deg


**C**
$$ u_c(t) = u_m sin(\omega t + \psi_{uC} ) $$

$$ u_c(t) = u_m \theta_{uC} $$

$$ \theta_{uC} = \omega t + \psi_{uC} $$

$$ i_c(t) = c {du_c \over dt} $$

$$ i_c(t) =  {c \ d \left[ u_m sin (\omega t + \psi_{uC}) \right] \over dt } $$

$$ i_c(t) = c \ \omega \ u_m cos(\omega t + \psi_{uC}) $$

$$ i_c(t) = c \ \omega \ u_m sin(\omega t + \psi_{uC} + {\pi \over 2}) $$

$$ i_c(t) = c \ \omega \ u_m sin \theta_{iC} $$

$$ \theta_{iC} = \omega t + \psi_{uC} + {\pi \over 2} $$

$$ \varphi = \theta_{uC} - \theta_{iC} $$

$$ \varphi = (\omega t + \psi_{uC}) - (\omega t - \psi_{iC} - {\pi \over 2}) $$

$$ \varphi = - {\pi \over 2} $$

$ \varphi < 0 $ current $ i $ overtakes the phase voltage $ u $ with 90 deg ($ - {\pi \over 2} $)

$\color{red} TODO: summary \ table  $
